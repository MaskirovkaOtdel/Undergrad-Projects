#include <iostream>
using namespace std;

	class LandVehicle {
		public:
		LandVehicle() {
			cout << "This is a Land Vehicle" << endl;
		}
	};
	
	class WaterVehicle {
		public:
		WaterVehicle() {
			cout << "This is a Water Vehicle" << endl;
		}
	};
	
	class AmphibiousVehicle : public LandVehicle, public WaterVehicle {
		public:
		AmphibiousVehicle() {
			cout << "This is an Amphibious Vehicle" << endl;
		}
	};
	
	int main() {
		AmphibiousVehicle obj;
		return 0;
	}