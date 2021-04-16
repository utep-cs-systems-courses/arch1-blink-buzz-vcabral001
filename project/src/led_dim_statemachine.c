#include <msp430.h>

#include "led_dim_statemachine.h"

#include "statemachine.h"

#include "led.h"

#include "switches.h"





// state variables

static enum {off=0, dim=1, bright=2} led_mode;

static char pwm_count = 0;



void

led_dim_slow_clock()/* slowly cycle through {off, dim, bright} */

{

  led_mode = (led_mode + 1) % 3;

}



void

led_dim_fast_clock()/* quickly cycle through 0...3 */

{

  pwm_count = (pwm_count + 1) & 3;

}



/**

 * Special state machine for dimming leds in msp430.

 * It changes from on to semi on to fully on to make the illusion as if it was dimmed. 

 */

void

led_dim_state_update()

{

  char new_led_on;

  switch (led_mode)

    {

    case off:

      new_led_on = 0; break;

    case bright:

      new_led_on = 1; break;

    case dim:

      new_led_on = (pwm_count < 1); break; /* 25% duty cycle */

    }

  if (switch_btn == SW2 && red_on != new_led_on)

    {

      red_on = new_led_on;

      led_changed = 1;

    }



  if (switch_btn == SW4 && green_on != new_led_on)

    {

      green_on = new_led_on;

      led_changed = 1;

    }

}

