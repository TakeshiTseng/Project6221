#ifndef __MOTOR_H__
#define __MOTOR_H__

struct motor {
	int id;
	int speed;
} motor_t;

int motor_set_speed(motor_t *motor, int speed);

#endif