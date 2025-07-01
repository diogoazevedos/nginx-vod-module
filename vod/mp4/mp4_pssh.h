#ifndef __MP4_PSSH_H__
#define __MP4_PSSH_H__

// includes
#include "../udrm.h"

// macros
#define mp4_pssh_is_common(info) \
	(vod_memcmp((info)->system_id, common_system_id, DRM_SYSTEM_ID_SIZE) == 0)

#define mp4_pssh_is_playready(info) \
	(vod_memcmp((info)->system_id, playready_system_id, DRM_SYSTEM_ID_SIZE) == 0)

// functions
u_char* mp4_pssh_write_box(u_char* p, drm_system_info_t* info);
u_char* mp4_pssh_write_boxes(void* context, u_char* p);

// globals
extern const u_char common_system_id[];
extern const u_char playready_system_id[];

#endif // __MP4_PSSH_H__
