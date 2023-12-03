max_red = 12
max_green = 13
max_blue = 14

counter = 0

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
    for i in range(len(line)):
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
                if (int(color[0]) > max_red):
                    print("ERROR: " + color[0] + " " + color[1])
                    fail_flag = True
                    break
            elif (color[1] == 'green'):
                if (int(color[0]) > max_green):
                    print("ERROR: " + color[0] + " " + color[1])
                    fail_flag = True
                    break
            elif (color[1] == 'blue'):
                if (int(color[0]) > max_blue):
                    print("ERROR: " + color[0] + " " + color[1])
                    fail_flag = True
                    break
    if (fail_flag == False):
        counter += int(game_ID)


# Print the counter
print(counter)
# Close file
file.close()
