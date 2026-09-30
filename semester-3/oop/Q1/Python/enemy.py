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
        player.take_damage(self.power)
        # Pass the enemy's power as the incoming damage to the player.

    def take_damage(self, incoming_damage):
        # TODO 2: Calculate damage_taken as (incoming_damage - self.defense).
        damage_taken = max(0, incoming_damage - self.defense)
        # Defense reduces the incoming damage. 
        # max() ensures that damage taken cannot be negative, so defense cannot accidentally increase the enemy's health.

        # TODO 3: Subtract the calculated damage_taken from self.health
        self.health -= damage_taken
        # Reduce the enemy's health by the calculated damage.

        # TODO 4: If self.health is lower than or equal to zero, print "{self.name} died!"
        if self.health <= 0:
            print(f"{self.name} died!")
        # If health reaches zero or below, the enemy has died.