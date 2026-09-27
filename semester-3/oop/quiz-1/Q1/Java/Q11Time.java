// File: Q11Time.java
public class Q11Time {
    public static int calculateAngle(int hours, int minutes) {
        // We calculate the hour angle for you (30 degrees per hour + 0.5 degrees per minute)
        double hourAngle = (hours % 12) * 30 + (minutes * 0.5);
        
        // TODO 1: Calculate the minute angle (6 degrees per minute)
        double minuteAngle = 0; // Replace 0 with your formula
        
        // Calculate the difference
        double angle = hourAngle - minuteAngle;
        
        // TODO 2: If the angle is less than 0, add 360 to normalize it.
        // Write your IF statement here:

        return (int) angle; 
    }

    public static void main(String[] args) {
        System.out.println("9:00 -> " + calculateAngle(9, 0));   // 270
        System.out.println("3:00 -> " + calculateAngle(3, 0));   // 90
        System.out.println("18:00 -> " + calculateAngle(18, 0)); // 180
        System.out.println("1:00 -> " + calculateAngle(1, 0));   // 30
        System.out.println("2:30 -> " + calculateAngle(2, 30));  // 255
        System.out.println("4:41 -> " + calculateAngle(4, 41));  // 254
    }
}