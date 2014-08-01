
int motor_set_speed(motor_t *motor, int speed) {

	if(motor != NULL && motor->id >= 0 && motor->id < 4) {
		motor->speed = speed;
	}
	
	// TODO
	// finish motor control with PID ? or linear ?

}