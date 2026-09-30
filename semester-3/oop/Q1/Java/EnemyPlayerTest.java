// File: EnemyPlayerTest.java
public class EnemyPlayerTest {
    public static void main(String[] args) {
        Player hero = new Player("Hero", 100, 25, 5);
        Enemy boss = new Enemy("Boss", 80, 20, 10);

        hero.attack(boss);
        boss.attack(hero);
    }
}