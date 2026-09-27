// File: Player.java
public class Player {
    private String name;
    private int health;
    private int power;
    private int defense;

    public Player(String name, int health, int power, int defense) {
        this.name = name;
        this.health = health;
        this.power = power;
        this.defense = defense;
    }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getPower() { return power; }
    public int getDefense() { return defense; }

    public void setHealth(int health) { this.health = health; }

    public void attack(Enemy enemy) {
        System.out.println(this.name + " attacks " + enemy.getName() + "!");
        enemy.takeDamage(this.power);
    }

    public void takeDamage(int incomingDamage) {
        int damageTaken = incomingDamage - this.defense;
        if (damageTaken < 0) damageTaken = 0; // Defense completely absorbs damage
        
        this.health -= damageTaken;
        System.out.println(this.name + " takes " + damageTaken + " damage. Health is now " + this.health);
        
        if (this.health <= 0) {
            System.out.println(this.name + " died!");
        }
    }
}
