The system is a menu-driven C program that records patient's heart rate, body temperature, and oxygen level, checks them against normal ranges, and keeps a running summary of the session.

The menu:

1. Record readings
2. Show session summary
3. Exit, with an “Are you sure?” check, so a mistaken choice doesn’t end the session.

The menu keeps coming back until the user confirms the exit. Any other input prints “Invalid input.”

1. Recording readings

The user enters how many patients to record.
For each patient, the program asks for a patient ID and keeps asking until it’s a positive number. It labels the patient Ward A if the ID is even and Ward B if it’s odd.
It then takes heart rate, temperature, and oxygen level in one line. Impossible values (a heart rate of 300, for example) are rejected with an error and asked for again, so they never count.
Each vital is checked against its normal range:
heart rate: 60 to 100
temperature: 36.1 to 37.2 °C
oxygen level: 95 to 100 %
The program counts how many vitals are abnormal (0 to 3), prints a message for that severity, and reports the patient as Stable (nothing abnormal) or Needs Attention.

2. Session summary
   
Across all patients recorded so far, it shows:

total valid readings,
how many were Stable and how many Needed Attention,
total abnormal vitals,
percentage of readings that were Stable,
average heart rate,
highest temperature, heart rate and oxygen level recorded.
