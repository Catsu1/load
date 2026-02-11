#ifndef LOAD_H
#define LOAD_H

#include "load_cfg.h"

typedef enum
{
	LOAD_OK,
	LOAD_ERROR_ID,
	LOAD_ERROR_NULL
} load_status_t;

typedef void *load_hw_t;

typedef struct
{
	load_status_t (*write)(load_hw_t hw, load_state_t state);
	load_status_t (*toggle)(load_hw_t hw);
} load_hal_t;

load_status_t load_init(load_id_t id, load_hw_t hw, const load_hal_t *hal, const load_cfg_t *cfg);
load_status_t load_set(load_id_t id, load_state_t state);
load_status_t load_toggle(load_id_t id);

#endif