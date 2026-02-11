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

#endif