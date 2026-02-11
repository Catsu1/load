#include <stddef.h>
#include "load.h"

#define LOAD_TRIGGERS	2U

typedef struct
{
	load_hw_t hw;
	const load_hal_t *hal;
	load_trigger_t trigger;
} load_instance_t;

static load_instance_t load_instances[LOAD_MAX];

static const load_state_t state_for_trigger[][LOAD_TRIGGERS] =
{
	{LOAD_ON, LOAD_OFF},
	{LOAD_OFF, LOAD_ON}
};

load_status_t load_init(load_id_t id, load_hw_t hw, const load_hal_t *hal, const load_cfg_t *cfg)
{
	if (id >= LOAD_MAX || id < 0)
	{
		return LOAD_ERROR_ID;
	}

	if (NULL == hal || NULL == cfg)
	{
		return LOAD_ERROR_NULL;
	}

	load_instance_t *inst = &load_instances[id];

	inst->hw = hw;
	inst->hal = hal;
	inst->trigger = cfg->trigger;

	return load_set(id, cfg->init_state);
}

load_status_t load_set(load_id_t id, load_state_t state)
{
	if (id < 0 || id >= LOAD_MAX)
	{
		return LOAD_ERROR_ID;
	}

	load_instance_t *inst = &load_instances[id];
	load_state_t mapped_state = state_for_trigger[state][inst->trigger];

	if (NULL == inst->hal || NULL == inst->hal->write)
	{
		return LOAD_ERROR_NULL;
	}

	return inst->hal->write(inst->hw, mapped_state);
}