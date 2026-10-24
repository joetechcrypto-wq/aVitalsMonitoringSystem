//A vitals monitoring system

#include <stdio.h>
#include <stdbool.h>
int main() {
  int menu;
  int abnormalVitals = 0;
  int noOfPatients;
  int validReadings = 0;
  bool active = true;
  int stableCount = 0;
  float stablePercentage;
  char confirm;
  int heartRate;
  float temperature;
  int oxygenLevel;
  bool impossibleVitals;
  int heartRateTotal = 0;
  int heartRateCount = 0;
  float highestTemp = 0;
  int highestHeartRate = 0;
  int highestOxygenLevel = 0;
  float averageHeartRate;
  do {
    printf("Press 1 to record a reading \n");
    printf("Press 2 to see session summary \n");
    printf("Press 3 to exit \n");

    scanf("%d", &menu);

    switch (menu) {
      case 1:
        int patientId;
        bool isHeartRateNormal;
        bool isTemperatureNormal;
        bool isOxygenLevelNormal;
        bool isStable;
       
        printf("Enter the number of patients: \n");
        scanf("%d", &noOfPatients);

        if(noOfPatients <= 0)
        {
          printf("Invalid input \n");
          break;
        }
        
        int a;
        for(a = 1; a <= noOfPatients; a++) {
          do {
            printf("Enter patient ID: \n");
            scanf("%d", &patientId);

            if(patientId <= 0)
            {
              printf("Invalid patient ID \n");
            }
          } while(patientId <= 0);
        
          bool ward = (patientId % 2 == 0);

          (ward) ? (printf("Ward A\n")) :
          (printf("Ward B\n"));


          do {
            printf("Enter patient heart rate: \n");
            printf("Enter patient temperature: \n");
            printf("Enter patient oxygen level: \n");

            scanf("%d %f %d", &heartRate, &temperature, &oxygenLevel);

            impossibleVitals = 
            (heartRate < 1 || heartRate > 250 ||
            temperature < 30.0 || temperature > 45.0 ||
            oxygenLevel < 0 || oxygenLevel > 100);
          
            if(impossibleVitals)
            {
              printf("Error...\n");
            }
          } while(impossibleVitals);
         

          if(temperature > highestTemp)
          {
            highestTemp = temperature;
          }

          if(heartRate > highestHeartRate)
          {
            highestHeartRate = heartRate;
          }

          if(oxygenLevel > highestOxygenLevel)
          {
            highestOxygenLevel = oxygenLevel;
          }

          if(heartRate >= 60 && heartRate <= 100)
          {
            isHeartRateNormal = true;
            validReadings++;
            stableCount++;
            heartRateTotal += heartRate;
            heartRateCount++;
          }

          else 
          {
            isHeartRateNormal = false;
            abnormalVitals++;
            validReadings++;
          }

          if(temperature >= 36.1 && temperature <= 37.2)
          {
            isTemperatureNormal = true;
            validReadings++;
            stableCount++;
          }

          else
          {
            isTemperatureNormal = false;
            abnormalVitals++;
            validReadings++;
          }
          
          if(oxygenLevel >= 95 && oxygenLevel <= 100)
          {
            isOxygenLevelNormal = true;
            validReadings++;
            stableCount++;
          }

          else
          {
            isOxygenLevelNormal = false;
            abnormalVitals++;
            validReadings++;
          }

          switch(abnormalVitals)
          {
            case 0:
              printf("0 abnormal vitals \n");
              break;
             
            case 1:
              printf("1 abnormal Vital \n");
              break;
              
            case 2:
              printf("2 abnormal vitals \n");
              break;

            case 3:
              printf("3 abnormal vitals \n");
              break;

            default:
              printf("invalid...");
          }

          isStable = isHeartRateNormal && isTemperatureNormal && isOxygenLevelNormal;

          (isStable) ? (printf("Patient is stable \n")) :
          (printf("Patient needs attention \n"));

        }
        break;

      case 2: 
        if(validReadings == 0)
        {
          printf("No valid readings \n");
        }

        printf("total valid readings = %d\n", validReadings);
        printf("Number of stable readings = %d\n", stableCount);
        printf("Number of abnormal readings = %d\n", abnormalVitals);

        stablePercentage = (stableCount/100);
        printf("Percentage of stable readings = %f\n", stablePercentage);
        
        averageHeartRate = heartRateTotal / heartRateCount;
        printf("Average heart rate = %f\n", averageHeartRate);

        printf("Highest temperature value = %f\n", highestTemp);
        printf("Highest heart rate value = %d \n", highestHeartRate);
        printf("Highest oxygen level = %d\n", highestOxygenLevel);
        break;  
      case 3:
        printf("Are you sure you want to exit? (y/n) \n");
        scanf(" %c", &confirm);
        
        if(confirm == 'y' || confirm == 'Y')
        {
          active = false;
        }

        else
        {
          printf("Returning to main menu \n");
        }
        break;

      default:
        printf("Invalid input \n");
    }
  } while(active);

  return 0;
}