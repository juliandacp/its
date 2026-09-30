# File: player.py
class Player:
    def __init__(self, name, health, power, defense):
        self.name = name
        self.health = health
        self.power = power
        self.defense = defense

    def attack(self, enemy):
        print(f"{self.name} attacks {enemy.name}!")
        enemy.take_damage(self.power)

    def take_damage(self, incoming_damage):
        damage_taken = max(0, incoming_damage - self.defense)
        self.health -= damage_taken
        
        print(f"{self.name} takes {damage_taken} damage. Health is now {self.health}")
        
        if self.health <= 0:
            print(f"{self.name} died!")