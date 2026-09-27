// File: Enemy.java
public class Enemy {
    // Properties are provided for you
    private String name;
    private int health;
    private int power;
    private int defense;

    // Constructor is provided for you
    public Enemy(String name, int health, int power, int defense) {
        this.name = name;
        this.health = health;
        this.power = power;
        this.defense = defense;
    }

    public String getName() { return this.name; }
    
    // TODO 1: Create the remaining getters and setters for health, power, and defense here

    public void attack(Player player) {
        System.out.println(this.name + " attacks " + player.getName() + "!");
        // TODO 2: Call the takeDamage() method on the 'player' object, passing this class's 'power' as the parameter
        
    }

    public void takeDamage(int incomingDamage) {
        // TODO 3: Calculate damageTaken as (incomingDamage - this.defense). 
        // Hint: Use Math.max(0, incomingDamage - this.defense) to ensure damage isn't negative.
        
        // TODO 4: Subtract the calculated damageTaken from this.health
        
        // TODO 5: If this.health is lower than or equal to zero, print "{this.name} died!"
        
    }
}
