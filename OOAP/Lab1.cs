public abstract class Character
{
  protected name string;
  protected strength int;
  protected dexterity int;
  protected endurance int;
  protected masteryOfFire int;
  protected masteryOfWater int;
  protected masteryOfAir int;
  protected masteryOfEarth int;
  protected light int;
  protected dark int;
  protected equippedPerks Perk[];
  protected equippedSpells Spell[9];
  protected equippedEquipment Equipment[6];
  public CalculateStats()
  {
    
  }
  public Equip(entity basicDevEntity)
  {
    //ченить умное с typeof и installationRemoval из BasicDevEntity
  }
}
public class Player: Character
{
 public SaveGame()
{}
}
public class Enemy: Character
{

}
public abstract class BasicDevEntity
{
  protected name string;
  protected minStrength int;
  protected minDexterity int;
  protected minEndurance int;
  protected minMasteryOfFire int;
  protected minMasteryOfWater int;
  protected minMasteryOfAir int;
  protected minMasteryOfEarth int;
  public CanBeUsed(character Character): bool
  {
    return ((character.GetStrength >= minStrength)&(character.GetDexterity >= minDexterity)&(character.GetEndurance >= minEndurance)&(character.GetMasteryOfFire >= minMasteryOfFire)&(character.GetMasteryOfWater >= minMasteryOfWater)&(character.GetMasteryOfEarth >= minMasteryOfEarth)&(character.GetMasteryOfAir) >= minMasteryOfAir))
  }
  public InstallationRemoval()
  {}
  public ApplyEffect()
  {}
}
public class Perk: basicDevEntity
{
  private level int;
  private characteristicRelated string;
}
public class Spell: basicDevEntity
{
  private manaCostFire int;
  private manaCostWater int;
  private manaCostEarth int;
  private manaCostAir int;
  public UseSpell()
  {}
}
public class Equipment: basicDevEntity
{
  private BodyPart int; //с учётом того что хранится это дело в массиве, так будет проще
}
public class Status //надо как-то привязать к Character'у???
{
  private duration int;
  public ApplyStatus(character Character)
  {}
}
