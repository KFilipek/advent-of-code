max_red = 12
max_green = 13
max_blue = 14

power_sum = 0

# Open file input
file = open('input.txt', 'r')
# Read the file
lines = file.readlines()
# Iterate over lines
for line in lines:
    # Split the line by ':'
    line = line.split(':')
    game_ID = line[0].split(' ')[1]
    print("Game ID: " + game_ID)
    # Split the line by ';'
    line = line[1].split(';') # Sety
    # Iterate over the splitted line
    fail_flag = False

    minimum_red = 0
    minimum_green = 0
    minimum_blue = 0

    for i in range(len(line)):
        # print(line[i])
        line[i] = line[i].split(',')
        if (len(line[i]) > 3):
            print("ERROR")
            exit(1)
        # Iterate over the splitted line
        for j in range(len(line[i])):
            # Remove spaces
            line[i][j] = line[i][j].strip()
            # Split the line by ' '
            color = line[i][j].split(' ')
            if (color[1] == 'red'):
                if (int(color[0]) > minimum_red):
                    minimum_red = int(color[0])
            elif (color[1] == 'green'):
                if (int(color[0]) > minimum_green):
                    minimum_green = int(color[0])
            elif (color[1] == 'blue'):
                if (int(color[0]) > minimum_blue):
                    minimum_blue = int(color[0])

    print(int(minimum_red) * int(minimum_green) * int(minimum_blue))
    power_sum += int(minimum_red) * int(minimum_green) * int(minimum_blue)

# Print the counter
print("Power sum: " + str(power_sum))

# Close file
file.close()
