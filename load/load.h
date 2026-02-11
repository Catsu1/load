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

#endif