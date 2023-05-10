#include <iostream>
#include <vector>

struct Wheel
{
	Wheel(float d) :Diameter(d) {};
	float Diameter = 0;
};

struct Engine
{
	Engine(float p) : Power(p) {};
	float Power = 0;
};

class Vehicle
{
public:
	virtual ~Vehicle() {};
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out , const Vehicle& veh)
	{
		return veh.print(out);
	}
};

class WaterVehicle :virtual public Vehicle
{
public:
	WaterVehicle(float WaterLine_) :WaterLine(WaterLine_) {};
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "WaterVehicle WaterLine: " << WaterLine;
		return out;
	}
protected:
	float WaterLine;
};

class RoadVehicle : virtual public Vehicle
{
public:
	RoadVehicle(float Draft_) : Draft(Draft_) {};
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Ride height: " << Draft;
		return out;
	}
protected:
	float Draft;
};

class Bicycle :virtual public RoadVehicle
{
protected:
	Wheel Forward, Backward;
public:
	Bicycle(Wheel f, Wheel b, float W) : Forward(f), Backward(b), RoadVehicle(W) {};
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Bicycle Wheels: " << Forward.Diameter << " " << Backward.Diameter<< " ";
		RoadVehicle::print(out);
		return out;
	}
};

class Car :virtual public RoadVehicle
{
protected:
	Engine engine;
	Wheel fl, fr, bl, br;
public:
	Car(Engine e, Wheel rl_, Wheel fr_, Wheel bl_, Wheel br_, float Draft_) : engine(e), fl(rl_), fr(fr_), bl(bl_), br(br_), RoadVehicle(Draft_){};
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Car Engine: " << engine.Power << " Wheels: " << fl.Diameter << " " << fr.Diameter << " " << bl.Diameter << " " << br.Diameter << " ";
		RoadVehicle::print(out); 
		return out;
	}
	float GetPower()const
	{
		return engine.Power;
	}
};

float getHighestPower(std::vector<Vehicle*> v)
{
	float Height = 0;
	for (auto c : v)
	{
		if (auto Car_ = dynamic_cast<Car*>(c))
		{
			Height = Height <= Car_->GetPower() ? Car_->GetPower() : Height;
		}
	}
	return Height;
}

int main()

{

	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

	

	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

	v.push_back(new WaterVehicle(5000));

	for (Vehicle* c : v)
	{
		std::cout << *c << std::endl;
	}

	std::cout << "The highest power is " << getHighestPower(v) << '\n';

	v.clear();

	/*Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);

	std::cout << c << '\n';



	Bicycle t(Wheel(20), Wheel(20), 300);

	std::cout << t << '\n';*/
	

	return 0;
}