#include "id3_encoder_filter.h"

// macros
#define THIS_FILTER (MEDIA_FILTER_ID3)
#define get_context(ctx) ((id3_encoder_state_t*)ctx->context[THIS_FILTER])

// macros
#define write_be32_synchsafe(p, dw)   \
	{                                 \
		*(p)++ = ((dw) >> 21) & 0x7F; \
		*(p)++ = ((dw) >> 14) & 0x7F; \
		*(p)++ = ((dw) >> 7) & 0x7F;  \
		*(p)++ = (dw) & 0x7F;         \
	}

// constants
// clang-format off
static u_char header_template[] = {
	// ID3 header
	0x49, 0x44, 0x33,       //ID3
	0x04,                   // version_major = 4
	0x00,                   // version_minor = 0
	0x00,                   // flags = 0
	0x00, 0x00, 0x00, 0x00, // size = 0 (syncsafe)

	// frame header
	0x54, 0x45, 0x58, 0x54, // TEXT
	0x00, 0x00, 0x00, 0x00, // frame_size
	0x00, 0x00,             // frame_flags

	// frame data
	0x03, // text_encoding (0x03 = utf8, null-terminated)
};
// clang-format on

static vod_status_t
id3_encoder_start_frame(media_filter_context_t* context, output_frame_t* frame) {
	id3_encoder_state_t* state = get_context(context);
	vod_status_t rc;
	uint32_t size = frame->size;
	u_char* p;

	// start the frame
	frame->size = size + sizeof(state->header);

	rc = state->start_frame(context, frame);
	if (rc != VOD_OK) {
		return rc;
	}

	// write the header
	p = state->header.frame_header.size;
	size += sizeof(id3_text_frame_header_t);
	write_be32_synchsafe(p, size);

	p = state->header.file_header.size;
	size += sizeof(id3_frame_header_t);
	write_be32_synchsafe(p, size);

	return state->write(context, (u_char*)&state->header, sizeof(state->header));
}

static void
id3_encoder_simulated_start_frame(media_filter_context_t* context, output_frame_t* frame) {
	id3_encoder_state_t* state = get_context(context);

	state->simulated_start_frame(context, frame);
	state->simulated_write(context, sizeof(state->header));
}

void
id3_encoder_init(id3_encoder_state_t* state, media_filter_t* filter, media_filter_context_t* context) {
	vod_memcpy(&state->header, header_template, sizeof(state->header));

	// save required functions
	state->start_frame = filter->start_frame;
	state->write = filter->write;
	state->simulated_start_frame = filter->simulated_start_frame;
	state->simulated_write = filter->simulated_write;

	// override functions
	filter->start_frame = id3_encoder_start_frame;
	filter->simulated_start_frame = id3_encoder_simulated_start_frame;

	// save the context
	context->context[THIS_FILTER] = state;
}
