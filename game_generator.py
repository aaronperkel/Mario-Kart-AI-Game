import random
import sys

number_of_players = sys.argv[1]

# name, laps, difficulty
COURSES = [("Amsterdam Drift", "3", "2"),
           ("Animal Crossing", "3", "2"),
           ("Athens Dash", "3", "2"),
           ("Baby Park", "7", "1"),
           ("Bangkok Rush", "3", "2"),
           ("Berlin Byways", "3", "2"),
           ("Big Blue", "3", "3"),
           ("Bone-Dry Dunes", "3", "4"),
           ("Boo Lake", "3", "3"),
           ("Bowser Castle 3 (SNES)", "3", "4"),
           ("Bowser's Castle (Wii U)", "3", "3"),
           ("Cheep Cheep Beach", "3", "3"),
           ("Cheese Land", "3", "2"),
           ("Choco Mountain", "3", "2"),
           ("City Tracks", "3", "3"),
           ("Cloudtop Cruise", "3", "5"),
           ("Coconut Mall", "3", "3"),
           ("Mount Wario", "3", "4"),
           ("Mario Circuit 3", "3", "2"),
           ("Moo Moo Meadows", "3", "2"),
           ("Yoshi's Island", "3", "3"),
           ("Yoshi Valley", "3", "2"),
           ("Yoshi Circuit", "3", "2"),
           ("Wild Woods", "3", "3"),
           ("Water Park", "3", "4"),
           ("Wario's Gold Mine", "3", "5"),
           ("Wario Stadium (DS)", "3", "3"),
           ("Waluigi Stadium (DS)", "3", "3"),
           ("Waluigi Pinball", "3", "4"),
           ("Mute City", "3", "4"),
           ("Snow Land", "3", "3"),
           ("Baby Park", "7", "1")]

# name, weight
CHARACTERS = [("Mario", "75.0"),
              ("Luigi", "75.0"),
              ("Peach", "50.0"),
              ("Daisy", "50.0"),
              ("Rosalina", "100.0"),
              ("Tanooki Mario", "100.0"),
              ("Cat Peach", "50.0"),
              ("Birdo", "50.0"),
              ("Yoshi", "50.0"),
              ("Toad", "25.0"),
              ("Koopa Troopa", "25.0"),
              ("Shy Guy", "25.0"),
              ("Lakitu", "25.0"),
              ("Toadette", "25.0"),
              ("King Boo", "100.0"),
              ("Petey Piranha", "100.0"),
              ("Baby Mario", "10.0"),
              ("Baby Luigi", "10.0"),
              ("Baby Peach", "10.0"),
              ("Baby Daisy", "10.0"),
              ("Baby Rosalina", "10.0"),
              ("Gold Mario", "100.0"),
              ("Pink Gold Peach", "100.0"),
              ("Wiggler", "75.0"),
              ("Wario", "125.0"),
              ("Waluigi", "100.0"),
              ("Donkey Kong", "100.0"),
              ("Bowser", "100.0"),
              ("Dry Bones", "10.0"),
              ("Bowser Jr.", "25.0"),
              ("Dry Bowser", "125.0"),
              ("Kamek", "50.0"),
              ("Lemmy", "10.0"),
              ("Larry", "25.0"),
              ("Wendy", "25.0"),
              ("Ludwig", "75.0"),
              ("Iggy", "75.0"),
              ("Roy", "100.0"),
              ("Morton", "125.0"),
              ("Inkling Girl", "50.0"),
              ("Inkling Boy", "50.0"),
              ("Link", "100.0"),
              ("Villager Male", "50.0"),
              ("Villager Female", "50.0"),
              ("Isabelle", "25.0"),
              ("Mii", "50.0"),
              ("Diddy Kong", "35.0"),
              ("Funky Kong", "100.0")]

# type, name, handling
VEHICLES = [("car", "Teddy Buggy", "0.7"),
            ("bike", "Yoshi Bike", "1.0"),
            ("car", "Mach 8", "0.65"),
            ("car", "Biddy Buggy", "0.75"),
            ("car", "Standard Kart", ".5"),
            ("car", "Pipe Frame", ".75"),
            ("car", "Cruiser", ".8"),
            ("car", "Circuit Special", ".25"),
            ("car", "Badwagon", ".1"),
            ("car", "Sneeker", ".3"),
            ("car", "Gold Standard", ".23"),
            ("car", "B Dasher", ".33"),
            ("car", "Streetle", ".85"),
            ("bike", "Standard Bike", ".55"),
            ("bike", "Sport Bike", ".7"),
            ("bike", "Flame Rider", ".5"),
            ("bike", "Mr. Scooty", ".9"),
            ("bike", "Jet Bike", ".7"),
            ("car", "Standard ATV", ".85")]


# name, size, traction
WHEELS = [("GLA Tires", "0.5", "0.1"),
          ("Rollers", "0.1", "0.2"),
          ("Cushion Tires", "1.0", "0.65"),
          ("Monster", "1.0", ".5"),
          ("Slim", ".4", ".6"),
          ("Slick", ".3", ".3"),
          ("Off-Road", ".4", ".7"),
          ("Wood", ".4", ".4"),
          ("Gold Tires", ".3", "3"),
          ("Standard", ".3", ".5"),
          ("Lead Tires", ".3", ".6")]

def random_courses():
    course_string = ''
    for _ in range(4):
        random_num = random.randint(0, len(COURSES) - 1)
        course_string += COURSES[random_num][0] + "\n" + COURSES[random_num][1] + "\n" + COURSES[random_num][2] + "\n"
    return course_string

def random_wheel():
    wheel_string = ''
    random_num = random.randint(0, len(WHEELS) - 1)
    wheel_string += WHEELS[random_num][0] + "\n" + WHEELS[random_num][1] + "\n" + WHEELS[random_num][2]
    return wheel_string

def random_vehicle():
    vehicle_string = ''
    random_num = random.randint(0, len(VEHICLES) - 1)
    vehicle_string += VEHICLES[random_num][0] + "\n" + VEHICLES[random_num][1] + "\n" + VEHICLES[random_num][2] + "\n" + random_wheel()
    return vehicle_string

def random_characters():
    character_string = ''
    for _ in range(int(number_of_players)):
        random_num = random.randint(0, len(CHARACTERS) - 1)
        character_string += CHARACTERS[random_num][0] + "\n" + CHARACTERS[random_num][1] + "\n" + random_vehicle() + "\n"
    return character_string

response = '4\n' + random_courses() + number_of_players + '\n' + random_characters()

file_game = open('GameFiles/new_game.txt' ,'w')
file_game.write(response)