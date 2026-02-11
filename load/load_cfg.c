#include "load_cfg.h"

static const load_cfg_t load_config[LOAD_MAX] =
{
    /* Add your load configurations here */
};

const load_cfg_t * load_get_config(load_id_t id)
{
	return &load_config[id];
}