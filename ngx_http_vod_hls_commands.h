#define BASE_OFFSET offsetof(ngx_http_vod_loc_conf_t, hls)

#if (NGX_HAVE_OPENSSL_EVP)
	{ ngx_string("vod_hls_encryption_method"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_enum_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, encryption_method),
	hls_encryption_methods },

	{ ngx_string("vod_hls_encryption_key_file_name"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.encryption_key_file_name),
	NULL },

	{ ngx_string("vod_hls_encryption_key_uri"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_http_set_complex_value_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, encryption_key_uri),
	NULL },

	{ ngx_string("vod_hls_encryption_key_format"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.encryption_key_format),
	NULL },

	{ ngx_string("vod_hls_encryption_key_format_versions"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.encryption_key_format_versions),
	NULL },

	{ ngx_string("vod_hls_encryption_output_iv"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, output_iv),
	NULL },
#endif // NGX_HAVE_OPENSSL_EVP

	{ ngx_string("vod_hls_version"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_num_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.m3u8_version),
	NULL },

	{ ngx_string("vod_hls_container_format"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_enum_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.container_format),
	hls_container_formats },

	{ ngx_string("vod_hls_absolute_master_urls"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, absolute_master_urls),
	NULL },

	{ ngx_string("vod_hls_absolute_index_urls"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, absolute_index_urls),
	NULL },

	{ ngx_string("vod_hls_absolute_iframe_urls"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, absolute_iframe_urls),
	NULL },

	{ ngx_string("vod_hls_master_file_name_prefix"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, master_file_name_prefix),
	NULL },

	{ ngx_string("vod_hls_index_file_name_prefix"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.index_file_name_prefix),
	NULL },

	{ ngx_string("vod_hls_output_iframes_playlist"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.output_iframes_playlist),
	NULL },

	{ ngx_string("vod_hls_iframes_file_name_prefix"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.iframes_file_name_prefix),
	NULL },

	{ ngx_string("vod_hls_segment_file_name_prefix"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.segment_file_name_prefix),
	NULL },

	{ ngx_string("vod_hls_init_file_name_prefix"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.init_file_name_prefix),
	NULL },

	{ ngx_string("vod_hls_mpegts_interleave_frames"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, interleave_frames),
	NULL },

	{ ngx_string("vod_hls_mpegts_align_frames"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, align_frames),
	NULL },

	{ ngx_string("vod_hls_mpegts_output_id3_timestamps"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, output_id3_timestamps),
	NULL },

	{ ngx_string("vod_hls_mpegts_id3_data"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_http_set_complex_value_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, id3_data),
	NULL },

	{ ngx_string("vod_hls_mpegts_align_pts"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, align_pts),
	NULL },

	{ ngx_string("vod_hls_force_unmuxed_segments"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	BASE_OFFSET + offsetof(ngx_http_vod_hls_loc_conf_t, m3u8_config.force_unmuxed_segments),
	NULL },

#undef BASE_OFFSET
