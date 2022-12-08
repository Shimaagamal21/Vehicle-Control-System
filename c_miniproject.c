#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0

struct vehicleReadings{
	int engineState;
	int ACpower;
	int engineTempController;
	char lightColour;
	int roomTemp;
	int engineTemp;
	int vehicleSpeed;

};

//functions prototypes
void getInput(void);
void displaySensorsSetMenu(void);
void trafficLightData(struct vehicleReadings * VR_ptr);
void roomTempData (struct vehicleReadings *VR_ptr);
void engineTempData(struct vehicleReadings *VR_ptr);
void displayCurrentState (struct vehicleReadings vehicleReading);
void handlingSpeed(struct vehicleReadings *VR_ptr);

char input1,input2;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct vehicleReadings VR = {OFF, OFF , OFF, 'G' ,35,90,100};    //intialvaluesforthestates
	getInput();
	while(input1!='c'){
		if(input1=='a'){
			VR.engineState = ON;
			displaySensorsSetMenu();
			if (input2=='a'){
				getInput();
				continue;
			}
			else if (input2=='b'){
				printf("Enter the Colour\n");
				scanf(" %c",&(VR.lightColour));
				trafficLightData(&VR);
			}
			else if (input2=='c'){
				printf("Enter the Room Temperature\n");
				scanf( " %d",&(VR.roomTemp));
				roomTempData(&VR);
			}
			else if (input2=='d'){
				printf("Enter the Engine Temperature\n");
				scanf(" %d",&(VR.engineTemp));
				engineTempData(&VR);
			}
			handlingSpeed(&VR);
			displayCurrentState(VR);
		}
		else if (input1=='b'){
			printf("Turn off the vehicle engine\n\n");
			getInput();
		}
	}
	if (input1 =='c'){
		printf("Quit the system");
		exit(0);             //to terminate the program in case the user entered c
	}
	return 0;
}
void getInput (void){
	printf("a-Turn on the vehicle engine\n");
	printf("b-Turn off the vehicle engine\n");
	printf("c-Quit the system\n");
	scanf(" %c",&input1);
}

void displaySensorsSetMenu(void){
	printf("a-Turn off the engine\n");
	printf("b-Set the traffic light color\n");
	printf("c-Set the room temperature\n");
	printf("d-Set the engine temperature\n");
	scanf(" %c",&input2);
}

void trafficLightData(struct vehicleReadings * VR_ptr){
	if (VR_ptr->lightColour=='G'){
		VR_ptr->vehicleSpeed = 100;
	}
	else if (VR_ptr->lightColour=='O'){
		VR_ptr->vehicleSpeed = 30;
	}
	else if (VR_ptr->lightColour=='R'){
		VR_ptr->vehicleSpeed = 0;
	}
}

void roomTempData (struct vehicleReadings *VR_ptr){

	if (VR_ptr->roomTemp <10 || 30< VR_ptr->roomTemp ){
		VR_ptr->roomTemp = 20;
		VR_ptr->ACpower = ON;
	}
	else{
		VR_ptr->ACpower = OFF;
	}
}

void engineTempData(struct vehicleReadings *VR_ptr){
	if(VR_ptr->engineTemp <100 || 150< VR_ptr->engineTemp){
		VR_ptr->engineTemp=125;
		VR_ptr->engineTempController= ON;
	}
	else{
		VR_ptr->engineTempController= OFF;
	}
}

void displayCurrentState (struct vehicleReadings vehicleReading){
	if (vehicleReading.engineState==1){
		printf("The Engine state: ON\n");
	}
	else{
		printf("The Engine state: OFF\n");
	}
	if (vehicleReading.ACpower==1){
		printf("AC: ON\n");
	}
	else{
		printf("AC: OFF\n");
	}
	printf("Vehicle Speed : %d Km/Hr\n" ,vehicleReading.vehicleSpeed);
	printf("Room Temperature : %d C\n" ,vehicleReading.roomTemp);
	if (vehicleReading.engineTempController==1){
		printf("Engine Temperature Controller state: ON\n");
	}
	else{
		printf("Engine Temperature Controller state: OFF\n");
	}
	printf("Engine Temperature: %d C\n\n",vehicleReading.engineTemp);

}

void handlingSpeed(struct vehicleReadings *VR_ptr){
	if ( VR_ptr->vehicleSpeed == 30){
		VR_ptr->ACpower=1;
		VR_ptr->roomTemp=(VR_ptr->roomTemp)*5/4 +1;
		VR_ptr->engineTempController=1;
		VR_ptr->engineTemp=(VR_ptr->engineTemp)*5/4 +1;
	}
}

