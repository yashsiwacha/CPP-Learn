//Task for using all variables in a well structured manner.
#include <stdio.h>

//Declaring a structure for sensor
struct sensor{
    //Declaring different variables for different inputs from the sensor and information of the sensor.
    char sensor_region_code;
    int current_reading_ID;
    float avg_soil_moisture; //Percentage(%)
    double light_intensity; //Lumens
    short temperature; //Celsius
    long number_of_readings_till_now;//Number of reading collected till now
    unsigned int threshold;//Threshold for sending data to server
    unsigned char sensor_mode;//Sensor is in active or idle mode
};
void sensor_input(struct sensor *s1){
    //Function to record all the inputs of the server
    printf("Enter the sendor region code: ");
    scanf(" %c", &s1->sensor_region_code);
    printf("Enter the  curent reading ID: ");
    scanf("%d", &s1->current_reading_ID);
    printf("Enter the average soil moisture: ");
    scanf("%f", &s1->avg_soil_moisture);
    printf("Enter the light intensity: ");
    scanf("%lf", &s1->light_intensity);
    printf("Enter the temperature: ");
    scanf("%hd", &s1->temperature);
    printf("Enter the number of reading collected till now: ");
    scanf("%ld", &s1->number_of_readings_till_now);
    printf("Enter the thresholf for sending data to server: ");
    scanf("%u", &s1->threshold);
    printf("Enter the sensor mode if its active or not: ");
    scanf("%hhu", &s1->sensor_mode);

}
void print_sensor_data(struct sensor s1){
    printf("Sensor Region Code: %c\n", s1.sensor_region_code);
    printf("Current Reading ID: %d\n", s1.current_reading_ID);
    printf("Average Soil Moisture: %.2f%%\n", s1.avg_soil_moisture);
    printf("Light Intensity: %.2lf lumens\n", s1.light_intensity);
    printf("Temperature: %hd Celsius\n", s1.temperature);
    printf("Number of reading collected till now: %ld\n", s1.number_of_readings_till_now);
    printf("Threshold before sending data to server: %u\n", s1.threshold);
    printf("Sensor Mode: ");
    if(s1.sensor_mode == 0x01) printf("Active\n");
    else printf("Idle\n");
}
int main(){
    struct sensor s1;
    sensor_input(&s1);
    print_sensor_data(s1);
    return 0;


}

