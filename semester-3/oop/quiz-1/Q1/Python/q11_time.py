# File: q11_time.py
def calculate_angle(hours, minutes):
    # We calculate the hour angle for you
    hour_angle = (hours % 12) * 30 + (minutes * 0.5)
    
    # TODO 1: Calculate the minute angle (6 degrees per minute)
    minute_angle = 0 
    
    angle = hour_angle - minute_angle
    
    # TODO 2: If angle is less than 0, add 360.
    
    return int(angle)
    
if __name__ == "__main__":
    print(f"9:00 -> {calculate_angle(9, 0)}")
    print(f"3:00 -> {calculate_angle(3, 0)}")
    print(f"18:00 -> {calculate_angle(18, 0)}")
    print(f"1:00 -> {calculate_angle(1, 0)}")
    print(f"2:30 -> {calculate_angle(2, 30)}")
    print(f"4:41 -> {calculate_angle(4, 41)}")