# File: enemy.py
class Enemy:
    def __init__(self, name, health, power, defense):
        # Properties are provided for you
        self.name = name
        self.health = health
        self.power = power
        self.defense = defense

    def attack(self, player):
        print(f"{self.name} attacks {player.name}!")
        # TODO 1: Call the take_damage() method on the 'player' object, passing this class's 'power' as the parameter
        pass

    def take_damage(self, incoming_damage):
        # TODO 2: Calculate damage_taken as (incoming_damage - self.defense).
        # Hint: Use max(0, incoming_damage - self.defense) to ensure damage isn't negative.
        
        # TODO 3: Subtract the calculated damage_taken from self.health
        
        # TODO 4: If self.health is lower than or equal to zero, print "{self.name} died!"
        pass
        