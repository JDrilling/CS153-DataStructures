/*Jacob Drilling
 *'allrobots.h'
 */
#include "robot.h"
#include <iostream>

using namespace std;


class Industrial: public Robot
{
  public:
    Industrial(int sources, string name)
      :Robot(name), pwrSources(sources){}

    virtual float speed() = 0;

    virtual float strength() = 0;

    virtual float toughness() = 0;

    virtual float intelligence() = 0;

 protected:
    int pwrSources;
};

class Bender: public Industrial
{
  public:
    Bender(string name, int pwrSources, int processors)
      :Industrial(pwrSources, name), coprocessors(processors){}
    
    float speed(){
      return ((.3*pwrSources) + (.02*coprocessors)< 0?0:
      (.3*pwrSources) + (.02*coprocessors));
    }

    float strength(){return (.55*pwrSources < 0?0:.55*pwrSources);}

    float toughness(){return Bender::TOUGHNESS;}

    float intelligence(){
      return (.34 + (1.3*coprocessors) < 0?0:
      .34 + (1.3*coprocessors));
    }

  private:
    int coprocessors;
    static const float TOUGHNESS = 3.1415;
};

class Welder: public Industrial
{
  public:
    Welder(string name, int pwrSources, int plates, float density)
      :Industrial(pwrSources, name), armorPlates(plates), armorDensity(density)
      {}

    float speed(){
      return ((.1*pwrSources)-(.22*armorPlates*armorDensity)<0?0:
      (.1*pwrSources)-(.22*armorPlates*armorDensity));
    }

    float strength(){return (3.15*pwrSources < 0?0:3.15*pwrSources);}

    float toughness(){
      return (5.19*armorPlates*armorDensity < 0?0:
      5.19*armorPlates*armorDensity);
    }

    float intelligence(){return Welder::INTELLIGENCE;}

 private:
    int armorPlates;
    float armorDensity;
    static const float INTELLIGENCE = .45;
};

class Domestic: public Robot
{
  public:
    Domestic(int cpu, int app, string name)
      :Robot(name), cpus(cpu), apps(app){}

    virtual float speed() = 0;

    virtual float strength() = 0;

    virtual float toughness() = 0;

    virtual float intelligence() = 0;

  protected:
    int cpus;
    int apps;
};

class Legged: public Domestic
{
  public:
    Legged(string name, int cpu, int app, int leg)
      :Domestic(cpu, app, name), legs(leg){}

    float speed(){
      return (7.15 - (.04*legs*legs) < 0?0:7.15 - (.04*legs*legs));
    }

    float strength(){return Legged::STRENGTH;}

    float toughness(){return (1.4/legs <0?0:1.4/legs);}

    float intelligence(){
      return (2.4*static_cast<float>(cpus)/apps < 0?0:
      2.4*static_cast<float>(cpus)/apps);
    }

 private:
    int legs;
    static const float STRENGTH = .123;
};

class Wheeled: public Domestic
{
  public:
    Wheeled(string name, int cpu, int app, int wheel)
      :Domestic(cpu, app, name), wheels(wheel){}

    float speed(){return .33*(wheels*wheels);}

    float strength(){return Wheeled::STRENGTH;}

    float toughness(){
      return (5.12 - (.7*wheels) <0?0:5.12 - (.7*wheels));}

    float intelligence(){
      return (1.3*static_cast<float>(cpus)/apps <0?0:
      1.3*static_cast<float>(cpus)/apps);
    }

 private:
    int wheels;
    static const float STRENGTH = 4.444;
};

class Hover: public Domestic
{
  public:
    Hover(string name, int cpu, int app, int rocket, int engine)
      :Domestic(cpu, app , name), rockets(rocket), engines(engine){}

    float speed(){return (.59*rockets*engines <0?0:.59*rockets*engines);}

    float strength(){return (1.12/engines <0?0:1.12/engines);}

    float toughness(){return Hover::TOUGHNESS;}

    float intelligence(){
      return (5.2*static_cast<float>(cpus)/apps - .8/rockets < 0?0:
      5.2*static_cast<float>(cpus)/apps - .8/rockets);
    }

 private:
    int rockets;
    int engines;//Anti-gravity that is.
    static const float TOUGHNESS = .99;
};

int main()
{
  Robot **robots;
  int numRobots, robotType;
  float stat1, stat2, stat3, stat4;
  string name;
  float avgSpeed = 0;
  float avgStr = 0;
  float avgTough = 0;
  float avgIntel = 0;
  Robot *fastest, *slowest, *strongest, *weakest; 
  Robot *toughest, *leastTough, *smartest, *dumbest;


  cin >> numRobots;
  robots = new Robot* [numRobots];


  //Begin Input
  for(int i = 0; i < numRobots; i++)
  {
    cin >> robotType >> name >> stat1 >> stat2;
    switch(robotType)
    {
      case BENDER:
        robots[i] = new Bender(name, stat1, stat2);
        break;
      case WELDER:
        cin >> stat3;
        robots[i] = new Welder(name, stat1, stat2, stat3);
        break;
      case LEGGED:
        cin >> stat3;
        robots[i] = new Legged(name, stat1, stat2, stat3);
        break;
      case WHEELED:
        cin >> stat3;
        robots[i] = new Wheeled(name, stat1, stat2, stat3);
        break;
      case HOVER:
        cin >> stat3 >> stat4;
        robots[i] = new Hover(name, stat1, stat2, stat3, stat4);
        break;
    }
    //Averages calculations;
    avgSpeed += robots[i]->speed();
    avgStr += robots[i]->strength();
    avgTough += robots[i]->toughness();
    avgIntel += robots[i]->intelligence();

    if( i == 0)//The first robot is the best at evertyhing.
    {
      fastest = slowest = strongest = weakest = robots[i];
      toughest = leastTough = smartest = dumbest = robots[i];
    }
    else //Do all the skills tests for each robot.
    {
      if(robots[i]->speed() > fastest->speed())
        fastest = robots[i];

      if(robots[i]->speed() < slowest->speed())
        slowest = robots[i];

      if(robots[i]->strength() > strongest->strength())
        strongest = robots[i];

      if(robots[i]->strength() < weakest->strength())
        weakest = robots[i];

      if(robots[i]->toughness() > toughest->toughness())
        toughest = robots[i];

      if(robots[i]->toughness() < leastTough->toughness())
        leastTough = robots[i];

      if(robots[i]->intelligence() > smartest->intelligence())
        smartest = robots[i];

      if(robots[i]->intelligence() < dumbest->intelligence())
        dumbest = robots[i];
    }
  }
  //End Input
  //avgs are still sums, so divide by numRobots.
  avgSpeed /= numRobots;
  avgStr /= numRobots;
  avgTough /= numRobots;
  avgIntel /= numRobots;
  
  //Begin Output
  //Speed
  cout << "[Speed]" << endl;
  cout << "The average speed is " << avgSpeed << " circus rings per second." << endl;
  cout << "The highest speed value is " << fastest->speed() 
       << " by " << fastest->getName() << "." << endl;
  cout << "The lowest speed value is " << slowest->speed() 
       << " by " << slowest->getName() << "." << endl;
 
  //Strength
  cout << "[Strength]" << endl;
  cout << "The average stregnth is " << avgStr << " dinasaur-power." << endl;
  cout << "The highest strength value is " << strongest->strength() 
       << " by " << strongest->getName() <<"." << endl;
  cout << "The lowest strength value is " << weakest->strength() 
       << " by " << weakest->getName() <<  "." << endl;
 
  //Toughness
  cout << "[Toughness]" << endl;
  cout << "The average toughness is " << avgTough << " wrecking-balls." << endl;
  cout << "The highest toughness value is " << toughest->toughness() 
       << " by " << toughest->getName() << "." << endl;
  cout << "The lowest toughness value is " << leastTough->toughness() 
       << " by " << leastTough->getName() << "." << endl;
  
  //Intelligence
  cout << "[Intelligence]" << endl;
  cout << "The average intelligence is " << avgIntel << " nano-Turings." << endl;
  cout << "The highest intelligence value is " << smartest->intelligence() 
       << " by " << smartest->getName() <<"." << endl;
  cout << "The lowest intelligence value is " << dumbest->intelligence() 
       << " by " << dumbest->getName() << "." << endl;

  for(int i =0; i < numRobots; i++)
    delete robots[i];

  delete [] robots;
  return 0;
}
