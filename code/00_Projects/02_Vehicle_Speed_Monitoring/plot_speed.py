import matplotlib.pyplot as plt

# Read the log file
speed_data = []
status_data = []

with open("speed_log.txt", "r") as file:
    for line in file:
        speed, status = line.strip().split(',')
        speed_data.append(int(speed))
        status_data.append(status)

# Generate x-axis for plotting
time_data = list(range(len(speed_data)))

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(time_data, speed_data, label="Vehicle Speed", marker='o')

# Highlight overspeeding points
for i, status in enumerate(status_data):
    if status == "ALERT":
        plt.scatter(time_data[i], speed_data[i], color='red', label="Overspeed Alert" if i == 0 else "")

# Add labels and legend
plt.axhline(y=80, color='gray', linestyle='--', label="Speed Limit (80 km/h)")
plt.title("Vehicle Speed Monitoring System")
plt.xlabel("Time (arbitrary units)")
plt.ylabel("Speed (km/h)")
plt.legend()
plt.grid()

# Show the plot
plt.show()
