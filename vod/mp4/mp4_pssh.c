#include "mp4_defs.h"
#include "mp4_pssh.h"
#include "mp4_init_segment.h"
#include "mp4_write_stream.h"
#include "../udrm.h"

// constants
const u_char common_system_id[] = {
	0x10, 0x77, 0xef, 0xec, 0xc0, 0xb2, 0x4d, 0x02, 0xac, 0xe3, 0x3c, 0x1e, 0x52, 0xe2, 0xfb, 0x4b
};

const u_char playready_system_id[] = {
	0x9a, 0x04, 0xf0, 0x79, 0x98, 0x40, 0x42, 0x86, 0xab, 0x92, 0xe6, 0x5b, 0xe0, 0x88, 0x5f, 0x95
};

u_char*
mp4_pssh_write_box(u_char* p, drm_system_info_t* info) {
	bool_t is_pssh_v1 = mp4_pssh_is_common(info); // W3C common PSSH box follows `v1` format
	size_t pssh_atom_size;

	pssh_atom_size = ATOM_HEADER_SIZE + sizeof(pssh_atom_t) + info->data.len;
	if (is_pssh_v1) {
		pssh_atom_size -= sizeof(uint32_t);
	}
	write_atom_header(p, pssh_atom_size, 'p', 's', 's', 'h');

	if (is_pssh_v1) {
		write_be32(p, 0x01000000); // version + flags
	} else {
		write_be32(p, 0); // version + flags
	}

	p = vod_copy(p, info->system_id, DRM_SYSTEM_ID_SIZE); // system ID

	if (!is_pssh_v1) {
		write_be32(p, info->data.len); // data size
	}

	p = vod_copy(p, info->data.data, info->data.len);

	return p;
}

u_char*
mp4_pssh_write_boxes(void* context, u_char* p) {
	drm_system_info_array_t* pssh_array = (drm_system_info_array_t*)context;
	drm_system_info_t* info;

	for (info = pssh_array->first; info < pssh_array->last; info++) {
		p = mp4_pssh_write_box(p, info);
	}

	return p;
}

void
mp4_pssh_init_atom_writer(drm_info_t* drm_info, atom_writer_t* atom_writer) {
	drm_system_info_t* cur_info;

	atom_writer->atom_size = 0;

	for (cur_info = drm_info->pssh_array.first; cur_info < drm_info->pssh_array.last; cur_info++) {
		atom_writer->atom_size += ATOM_HEADER_SIZE + sizeof(pssh_atom_t) + cur_info->data.len;
		if (mp4_pssh_is_common(cur_info)) {
			atom_writer->atom_size -= sizeof(uint32_t);
		}
	}

	atom_writer->write = mp4_pssh_write_boxes;
	atom_writer->context = &drm_info->pssh_array;
}
