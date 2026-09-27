# File: enemy_player_test.py
from player import Player
from enemy import Enemy

if __name__ == "__main__":
    hero = Player("Hero", 100, 25, 5)
    boss = Enemy("Boss", 80, 20, 10)

    hero.attack(boss)
    boss.attack(hero)