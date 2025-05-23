#include "ngx_http_vod_dash.h"
#include "ngx_http_vod_hls.h"

#if (NGX_HAVE_LIB_AV_CODEC)
#include "ngx_http_vod_thumb.h"
#include "ngx_http_vod_volume_map.h"
#endif // NGX_HAVE_LIB_AV_CODEC

const ngx_http_vod_submodule_t* submodules[] = {
	&dash,
	&hls,
#if (NGX_HAVE_LIB_AV_CODEC)
	&thumb,
	&volume_map,
#endif // NGX_HAVE_LIB_AV_CODEC
	NULL,
};
