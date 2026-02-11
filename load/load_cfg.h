#ifndef LOAD_CFG_H
#define LOAD_CFG_H

typedef enum
{
    /* Define your loads here */
	LOAD_MAX
} load_id_t;

typedef enum
{
	LOAD_ON,
	LOAD_OFF
} load_state_t;

typedef enum
{
	LOAD_TRIGGER_HIGH,
	LOAD_TRIGGER_LOW
} load_trigger_t;

typedef struct
{
	load_state_t init_state;
	load_trigger_t trigger;
} load_cfg_t;

const load_cfg_t * load_get_config(load_id_t id);

#endif