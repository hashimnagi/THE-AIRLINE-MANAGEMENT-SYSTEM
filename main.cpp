#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Person {
	private:
	string name;
	int age;
	string passportNumber;
	string nationality;
	string contactNumber;
	public:
	Person(string n , int a , string pN , string nat , string cN) : age(a) {
		name = n;
		passportNumber = pN;
		nationality = nat;
		contactNumber = cN;
	}

	Person(const Person &p) {
		this->age = p.age;
		this->contactNumber = p.contactNumber;
		this->name = p.name;
		this->nationality = p.nationality;
		this->passportNumber = p.passportNumber;

		cout << "Copy constructor for " << this->name << "Is called" << endl;
	}

	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setPassportNumber(string pN) {
		passportNumber = pN;
	}
	void setNationality(string nat) {
		nationality = nat;
	}
	void setConatactNumber(string cN) {
		contactNumber = cN;
	}

	string getName( ) {
		return name;
	}
	int getAge( ) {
		return age;
	}
	string getPassportNumber( ) {
		return passportNumber;
	}
	string getNationality( ) {
		return nationality;
	}
	string getConatactNumber( ) {
		return contactNumber;
	}

	virtual void display( ) {
		cout << "NAME:           " << setw(4) << name << endl;
		cout << "AGE:            " << setw(4) << age << endl;
		cout << "PASSPORT NUMBER:" << setw(4) << passportNumber << endl;
		cout << "NATIONALITY:    " << setw(4) << nationality << endl;
		cout << "CONTACT NUMBER: " << setw(4) << contactNumber << endl;
	}

	virtual ~Person( ) {
		cout << name << "'s record removed." << endl;
	}

};

class Staff :public Person {
	private:
	string employeeId;
	string department;
	float monthlySalary;
	string joiningDate;
	public:
	Staff(string n , int a , string pN , string nat , string cN,string eid,
		  string d, float mS,string jD) :Person(n,a,pN,nat,cN ) {
		employeeId = eid;
		department = d;
		monthlySalary = mS;
		joiningDate = jD;
	};

	void setEmployeeId(string eid) {
		employeeId = eid;
	}
	void setDepartment(string d) {
		department = d;
	}
	void setMothlySalary(float mS) {
		monthlySalary = mS;
	}
	void setJpiningDate(string jD) {
		joiningDate = jD;
	}

	string getEmployeeId( ) {
		return employeeId;
	}
	string getDepartment( ) {
		return department;
	}
	float getMonthlySalary( ) {
		return monthlySalary;
	}
	string getJoiningDate( ) {
		return joiningDate;
	}

	void display( ) override {
		cout << "EMPLOYEE ID:    " << setw(4) << employeeId << endl;
		cout << "DEPARTMENT:     " << setw(4) << department << endl;
		cout << "MOTHLY SALARY:  " << setw(4) << monthlySalary << endl;
		cout << "JOINING DATE:   " << setw(4) << joiningDate << endl;
	}

	~Staff( ) {
		cout << "STAFF's " << employeeId << "removed from system." << endl;
	}
};

class Pilot :public Staff {
	private:
	string licenseNumber;
	float totalFlightHours;
	string airCraftType;
	public:

	Pilot(string n , int a , string pN , string nat , string cN ,
		  string eid , string d , float mS , string jD , string lN ,
		  float fH , string cT) : Staff(n , a , pN , nat , cN , eid , d , mS , jD) {
		licenseNumber = lN;
		totalFlightHours = fH;
		airCraftType = cT;
	}

	void setLicenseNumber(string lN) {
		licenseNumber = lN;
	}
	void setTotalFlightHours(float fH) {
		totalFlightHours = fH;
	}
	void setAirCraftType(string cT) {
		airCraftType = cT;
	}

	string getLicenseNumber( ) {
		return licenseNumber;
	}
	float getTotalFlightHours( ) {
		return totalFlightHours;
	}
	string getAirCraftType( ) {
		return airCraftType;
	}

	void display( ) override{
		cout << "LICENSE NUMBER:     " << setw(4) << licenseNumber << endl;
		cout << "TOTAL FLIGHT HOURS: " << setw(4) << totalFlightHours << endl;
		cout << "AIR CRAFT TYPE:     " << setw(4) << airCraftType << endl;
	}

	~Pilot( ) {
		cout << "PILOT: " << this->getName( ) << "LICENSE NUMBER" << this->getLicenseNumber( )
			<< "removed from system." << endl;
	}
};

class CabinetCrew :public Staff {
	private:
	string role;
	string languageSpoken;
	string assignedSection;
	public:

	CabinetCrew(string n , int a , string pN , string nat , string cN ,
		  string eid , string d , float mS , string jD , string r , string lS ,
		  string aS) : Staff(n , a , pN , nat , cN , eid , d , mS , jD) {
		role = r;
		languageSpoken = lS;
		assignedSection = aS;

	}
	void setRole(string r) {
		role = r;
	}
	void setLanguageSpoken(string lS) {
		languageSpoken = lS;
	}
	void setAssignedSection(string aS) {
		assignedSection = aS;
	}

	string getRole( ) {
		return role;
	}
	string getLanguageSpoken( ) {
		return languageSpoken;
	}
	string getAssignedSection( ) {
		return assignedSection;
	}

	~CabinetCrew( ) {
		cout << "CABINET CREW: " << this->getName( ) << "EMPLOYEEE ID: " << this->getEmployeeId( ) <<
			"removed from records." << endl;
	}

	void display( )override {
		cout << "ROLE:            " << setw(4) << role << endl;
		cout << "LANGUAGE SPOKEN: " << setw(4) << languageSpoken << endl;
		cout << "ASSIGNED SECTION:" << setw(4) << assignedSection << endl;
	}
};

class Passenger :public Person {
	private:
	string passengerId;
	int frequentFlyerMiles;
	string seatPreface;
	string mealPreface;
	public:
	Passenger(string n , int a , string pN , string nat , string cN ,
			  string pid , int fM , string sP , string mP) : Person(n , a , pN , nat , cN) {
		passengerId = pid;
		frequentFlyerMiles = fM;
		seatPreface = sP;
		mealPreface = mP;
	}

	Passenger(const Passenger &pa) : Person(pa) {
		this->passengerId = pa.passengerId;
		this->frequentFlyerMiles = pa.frequentFlyerMiles;
		this->seatPreface = pa.seatPreface;
		this->mealPreface = pa.mealPreface;
	}

	void setPassengerId(string pid) {
		passengerId = pid;
	}
	void setFrequentFlyMiles(int fM) {
		frequentFlyerMiles = fM;
	}void setSeatPreface(string sP) {
		seatPreface = sP;
	}void setMealPreface(string mP) {
		mealPreface = mP;
	}

	string getPassengerId( ) {
		return passengerId;
	}
	int getFrequentlyFlyMiles( ) {
		return frequentFlyerMiles;
	}
	string getSeatPreface( ) {
		return seatPreface;
	}
	string getMealPreface( ) {
		return mealPreface;
	}

	void display( ) override{
		cout << "PASSENGER ID:      " << setw(4) << passengerId << endl;
		cout << "FREQUENT FLY HOURS:" << setw(4) << frequentFlyerMiles << endl;
		cout << "SEAT PREFACE:      " << setw(4) << seatPreface << endl;
		cout << "MEAL PREFACE:      " << setw(4) << mealPreface << endl;
	}

};

class BaggageInfo {
	private:
	string baggageId;
	float weightKg;
	int numberofBags;
	string baggageStatus;
	public:

	BaggageInfo(string bid , float wK , int nB , string bS) : weightKg(wK) , numberofBags(nB) {
		baggageId = bid;
		baggageStatus = bS;
	}

	void setBaggageId(string bid) {
		baggageId = bid;
	}
	void setWeightKg(float wK) {
		weightKg = wK;
	}
	void setNumberofBags(int nB) {
		numberofBags = nB;
	}
	void setBaggageStatus(string bS) {
		baggageStatus = bS;
	}

	string getBaggageId( ) {
		return baggageId;
	}
	float getWeightKg( ) {
		return weightKg;
	}
	int getNumberofBags( ) {
		return numberofBags;
	}
	string getBaggageStatus( ) {
		return baggageStatus;
	}

	void Display( ) {
		cout << "BAGGAGE ID:    " << setw(4) << baggageId << endl;
		cout << "WEIGHT IN KG's:" << setw(4) << weightKg << endl;
		cout << "TOTAL BAGS:    " << setw(4) << numberofBags << endl;
		cout << "BAGGAGE STATUS:" << setw(4) << baggageStatus << endl;
	}

};

class Ticket {
	private:
	string ticketNumber;
	string seatNumber;
	string ticketClass;
	float price;
	string bookingDate;
	BaggageInfo baggage;
	public:
	Ticket(string bid , float wK , int nB , string bS ,
		   string tN , string sN , string tC , float p , string bD) :baggage(bid,wK,nB,bS) {
		ticketNumber = tN;
		seatNumber = sN;
		ticketClass = tC;
		price = p;
		bookingDate = bD;
	}

	void display( ) const{
		cout << "TICKET NUMBER:" << setw(4) << ticketNumber << endl;
		cout << "SEAT NUMBER:  " << setw(4) << seatNumber << endl;
		cout << "TICKET CLASS: " << setw(4) << ticketClass << endl;
		cout << "TICKET PRICE: " << setw(4) << price << endl;
		cout << "BOOKING DATE: " << setw(4) << bookingDate << endl;
	}
	~Ticket( ) {
		cout << "TICKET NUMBER: " << ticketNumber << "removed from system." << endl;
    }
};

class Flight {
	private:
	string flightNumber;
	string origin;
	string destination;
	string departureTime;
	string arriveTime;
	int totalSeats;
	Pilot *assignedPilot;
	CabinetCrew *assignedCrew;
	public:

	Flight(string fN , string o , string d , string dT , string aT , int tS
		  , Pilot *aP , CabinetCrew *aC) {
		flightNumber = fN;
		origin = o;
		destination = d;
		departureTime = dT;
		arriveTime = aT;
		totalSeats = tS;
		assignedPilot = aP;
		assignedCrew = aC;
	}

	void display( ) {
		cout << "FLIGHT NUMBER: " << setw(4) << flightNumber << endl;
		cout << "ORIGIN:        " << setw(4) << origin << endl;
		cout << "DESTINATION:   " << setw(4) << destination << endl;
		cout << "DEPARTURE TIME:" << setw(4) << departureTime << endl;
		cout << "ARRIVE TIME:   " << setw(4) << arriveTime << endl;
		cout << "TOTAL SEATS:   " << setw(4) << totalSeats << endl;
		cout << setw(5) << "ASSIGNED PILOT:   " << "\n";
		assignedPilot->display( );
		cout << setw(5) << "ASSIGNNED CREW:   " << "\n";
		assignedCrew->display( );
	}
	~Flight( ) {
			cout << "Flight " << flightNumber << " removed." << endl;
	}

};

class ExperiencedFlyer : public virtual Person {
	private:
	int totalMissions;
	string awardBadges;
	public:

	ExperiencedFlyer(string n , int a , string pN , string nat , string cN, int tM, string aB) : 
		Person(n , a , pN , nat , cN) {
		totalMissions = tM;
		awardBadges = aB;
	}

	void setTotalMissions(int tM ) {
		totalMissions = tM;
	}
	void setAwardsBadges(string aB) {
		awardBadges = aB;
	}

	int getTotalMissions( ) {
		return totalMissions;
	}
	string getAwardsBadges( ) {
		return awardBadges;
	}
};

class InstructorPilot : public virtual Person {
	private:
	int studentsTrainedCount;
	string trainingCertification;
	public:
	InstructorPilot(string n , int a , string pN , string nat , string cN , int sT , string tC) :
		Person(n , a , pN , nat , cN) {
		studentsTrainedCount = sT;
		trainingCertification = tC;
	}

	void setTrainingCertification(string tC ) {
		trainingCertification = tC;
	}
	void etStudentsTrainedCount(int  sT) {
		studentsTrainedCount = sT;
	}
	string getTrainingCertification( ) {
		return trainingCertification;
	}
	int getStudentsTrainedCount( ) {
		return studentsTrainedCount;
	}
};

class SeniorPilot : public ExperiencedFlyer , public InstructorPilot {
	private:
	string seniorityLevel;
	int yearsofService;
	public:
	SeniorPilot(string n , int a , string pN , string nat , string cN ,
			   int tM , string aB ,
			   string tC , int sT ,
			   string l , int y)

		: Person(n , a , pN , nat , cN) ,                       
		ExperiencedFlyer(n , a , pN , nat , cN , tM , aB) ,
		InstructorPilot(n , a , pN , nat , cN , sT , tC) {
		seniorityLevel = l;
		yearsofService = y;
	}

	void display( ) override {
		cout << setw(5) << "Senior Pilot Profile" << endl;
		Person::display( );   
		cout << "Total Missions:     " << setw(4) << getTotalMissions( ) << endl;
		cout << "Awards/Badges:      " << setw(4) << getAwardsBadges( ) << endl;
		cout << "Certification:      " << setw(4) << getTrainingCertification( ) << endl;
		cout << "Students Trained:   " << setw(4) << getStudentsTrainedCount( ) << endl;
		cout << "Seniority Level:    " << setw(4) << seniorityLevel << endl;
		cout << "Years of Service:   " << setw(4) << yearsofService << endl;
	}

	~SeniorPilot( ) {
		cout << "SeniorPilot " << getName( ) << " record removed." << endl;
	}
};

//void displayMenu( ) {
//	do {
//		cout << "============================================" << endl;
//		cout << "          Al Hashim Airways System          " << endl;
//		cout << "============================================" << endl;
//		cout << 
//
//
//	}
//}

void clearScreen( ) {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void displayMenu( ) {
	cout << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "  |       Al Hashim AIRLINE RESERVATION SYSTEM       |" << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "  |  REGISTER                                        |" << endl;
	cout << "  |   [01] Register a Pilot                          |" << endl;
	cout << "  |   [02] Register a Cabin Crew Member              |" << endl;
	cout << "  |   [03] Register a Passenger                      |" << endl;
	cout << "  |   [04] Register a Senior Pilot                   |" << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "  |  ACTIONS                                         |" << endl;
	cout << "  |   [05] Schedule a Flight                         |" << endl;
	cout << "  |   [06] Book a Ticket                             |" << endl;
	cout << "  |   [07] Copy a Passenger Profile                  |" << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "  |  VIEW RECORDS                                    |" << endl;
	cout << "  |   [08] Display all Pilots                        |" << endl;
	cout << "  |   [09] Display all Cabin Crew                    |" << endl;
	cout << "  |   [10] Display all Passengers                    |" << endl;
	cout << "  |   [11] Display all Flights                       |" << endl;
	cout << "  |   [12] Display all Tickets                       |" << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "  |   [13] Exit System                               |" << endl;
	cout << "  +--------------------------------------------------+" << endl;
	cout << "\nEnter choice: ";
}

int main( ) {

	const int MAX = 100;

	
	Pilot *pilots [ MAX ];       int pilotCount = 0;
	CabinetCrew *crew [ MAX ];         int crewCount = 0;
	Passenger *passengers [ MAX ];   int passengerCount = 0;
	SeniorPilot *seniorPilots [ MAX ]; int seniorCount = 0;
	Flight *flights [ MAX ];      int flightCount = 0;
	Ticket *tickets [ MAX ];      int ticketCount = 0;

	int choice;

	do {
		displayMenu( );
		cin >> choice;
		cin.ignore( );

		switch ( choice ) {

			case 1:
				{
					string n , pN , nat , cN , eid , dep , jD , lN , cT;
					int    a;
					float  mS , fH;

					cout << "\n  --- Register Pilot ---\n";
					cout << "  Name            : "; getline(cin , n);
					cout << "  Age             : "; cin >> a;   cin.ignore( );
					cout << "  Passport Number : "; getline(cin , pN);
					cout << "  Nationality     : "; getline(cin , nat);
					cout << "  Contact Number  : "; getline(cin , cN);
					cout << "  Employee ID     : "; getline(cin , eid);
					cout << "  Department      : "; getline(cin , dep);
					cout << "  Monthly Salary  : "; cin >> mS;  cin.ignore( );
					cout << "  Joining Date    : "; getline(cin , jD);
					cout << "  License Number  : "; getline(cin , lN);
					cout << "  Flight Hours    : "; cin >> fH;  cin.ignore( );
					cout << "  Aircraft Type   : "; getline(cin , cT);

					pilots [ pilotCount++ ] = new Pilot(n , a , pN , nat , cN ,
													  eid , dep , mS , jD ,
													  lN , fH , cT);
					cout << "\n  Pilot registered successfully!\n";
					break;
				}

			case 2:
				{
					string n , pN , nat , cN , eid , dep , jD , r , lS , aS;
					int   a;
					float mS;

					cout << "\n  --- Register Cabin Crew ---\n";
					cout << "  Name             : "; getline(cin , n);
					cout << "  Age              : "; cin >> a;  cin.ignore( );
					cout << "  Passport Number  : "; getline(cin , pN);
					cout << "  Nationality      : "; getline(cin , nat);
					cout << "  Contact Number   : "; getline(cin , cN);
					cout << "  Employee ID      : "; getline(cin , eid);
					cout << "  Department       : "; getline(cin , dep);
					cout << "  Monthly Salary   : "; cin >> mS; cin.ignore( );
					cout << "  Joining Date     : "; getline(cin , jD);
					cout << "  Role             : "; getline(cin , r);
					cout << "  Language Spoken  : "; getline(cin , lS);
					cout << "  Assigned Section : "; getline(cin , aS);

					crew [ crewCount++ ] = new CabinetCrew(n , a , pN , nat , cN ,
														  eid , dep , mS , jD ,
														  r , lS , aS);
					cout << "\n  Cabin Crew registered successfully!\n";
					break;
				}

			case 3:
				{
					string n , pN , nat , cN , pid , sP , mP;
					int    a , fM;

					cout << "\n  --- Register Passenger ---\n";
					cout << "  Name            : "; getline(cin , n);
					cout << "  Age             : "; cin >> a;  cin.ignore( );
					cout << "  Passport Number : "; getline(cin , pN);
					cout << "  Nationality     : "; getline(cin , nat);
					cout << "  Contact Number  : "; getline(cin , cN);
					cout << "  Passenger ID    : "; getline(cin , pid);
					cout << "  Frequent Miles  : "; cin >> fM; cin.ignore( );
					cout << "  Seat Preference : "; getline(cin , sP);
					cout << "  Meal Preference : "; getline(cin , mP);

					passengers [ passengerCount++ ] = new Passenger(n , a , pN , nat , cN ,
																   pid , fM , sP , mP);
					cout << "\n  Passenger registered successfully!\n";
					break;
				}

			case 4:
				{
					string n , pN , nat , cN , aB , tC , l;
					int    a , tM , sT , y;

					cout << "\n  --- Register Senior Pilot ---\n";
					cout << "  Name              : "; getline(cin , n);
					cout << "  Age               : "; cin >> a;  cin.ignore( );
					cout << "  Passport Number   : "; getline(cin , pN);
					cout << "  Nationality       : "; getline(cin , nat);
					cout << "  Contact Number    : "; getline(cin , cN);
					cout << "  Total Missions    : "; cin >> tM; cin.ignore( );
					cout << "  Awards / Badges   : "; getline(cin , aB);
					cout << "  Training Cert     : "; getline(cin , tC);
					cout << "  Students Trained  : "; cin >> sT; cin.ignore( );
					cout << "  Seniority Level   : "; getline(cin , l);
					cout << "  Years of Service  : "; cin >> y;  cin.ignore( );

					seniorPilots [ seniorCount++ ] = new SeniorPilot(n , a , pN , nat , cN ,
																	tM , aB ,
																	tC , sT ,
																	l , y);
					cout << "\n  Senior Pilot registered successfully!\n";
					break;
				}

			case 5:
				{
					if ( pilotCount == 0 || crewCount == 0 ) {
						cout << "\n  Register at least one Pilot and one Cabin Crew first.\n";
						break;
					}

					string fN , o , dest , dT , aT;
					int    tS , pIdx , cIdx;

					cout << "\n  --- Schedule a Flight ---\n";
					cout << "  Flight Number  : "; getline(cin , fN);
					cout << "  Origin         : "; getline(cin , o);
					cout << "  Destination    : "; getline(cin , dest);
					cout << "  Departure Time : "; getline(cin , dT);
					cout << "  Arrival Time   : "; getline(cin , aT);
					cout << "  Total Seats    : "; cin >> tS; cin.ignore( );

					cout << "\n  Available Pilots:\n";
					for ( int i = 0; i < pilotCount; i++ )
						cout << "    [" << i + 1 << "] " << pilots [ i ]->getName( ) << "\n";
					cout << "  Select Pilot   : "; cin >> pIdx; cin.ignore( );

					cout << "\n  Available Cabin Crew:\n";
					for ( int i = 0; i < crewCount; i++ )
						cout << "    [" << i + 1 << "] " << crew [ i ]->getName( ) << "\n";
					cout << "  Select Crew    : "; cin >> cIdx; cin.ignore( );

					if ( pIdx < 1 || pIdx > pilotCount ||
						 cIdx < 1 || cIdx > crewCount ) {
						cout << "\n  Invalid selection. Flight not scheduled.\n";
						break;
					}

					flights [ flightCount++ ] = new Flight(fN , o , dest , dT , aT , tS ,
														 pilots [ pIdx - 1 ] ,
														 crew [ cIdx - 1 ]);
					cout << "\n  Flight scheduled successfully!\n";
					break;
				}

			case 6:
				{
					if ( passengerCount == 0 ) {
						cout << "\n  Register a Passenger first.\n";
						break;
					}

					string tN , sN , tC , bD , bid , bS;
					float  p , wK;
					int    nB , pIdx;

					cout << "\n  --- Book a Ticket ---\n";

					cout << "  Available Passengers:\n";
					for ( int i = 0; i < passengerCount; i++ )
						cout << "    [" << i + 1 << "] " << passengers [ i ]->getName( ) << "\n";
					cout << "  Select Passenger : "; cin >> pIdx; cin.ignore( );

					if ( pIdx < 1 || pIdx > passengerCount ) {
						cout << "\n  Invalid selection.\n";
						break;
					}

					cout << "  Ticket Number    : "; getline(cin , tN);
					cout << "  Seat Number      : "; getline(cin , sN);
					cout << "  Ticket Class     : "; getline(cin , tC);
					cout << "  Price            : "; cin >> p;  cin.ignore( );
					cout << "  Booking Date     : "; getline(cin , bD);

					cout << "\n  -- Baggage Info --\n";
					cout << "  Baggage ID       : "; getline(cin , bid);
					cout << "  Weight (kg)      : "; cin >> wK; cin.ignore( );
					cout << "  Number of Bags   : "; cin >> nB; cin.ignore( );
					cout << "  Baggage Status   : "; getline(cin , bS);

					tickets [ ticketCount++ ] = new Ticket(bid , wK , nB , bS ,
														 tN , sN , tC , p , bD);
					cout << "\n  Ticket booked for "
						<< passengers [ pIdx - 1 ]->getName( ) << " successfully!\n";
					break;
				}

			case 7:  
				{
					if ( passengerCount == 0 ) {
						cout << "\n  No passengers available to copy.\n";
						break;
					}

					int pIdx;
					cout << "\n  --- Copy Passenger Profile ---\n";
					cout << "  Available Passengers:\n";
					for ( int i = 0; i < passengerCount; i++ )
						cout << "    [" << i + 1 << "] " << passengers [ i ]->getName( ) << "\n";
					cout << "  Select Passenger to copy : "; cin >> pIdx; cin.ignore( );

					if ( pIdx < 1 || pIdx > passengerCount ) {
						cout << "\n  Invalid selection.\n";
						break;
					}

					Passenger *copiedPassenger = new Passenger(*passengers [ pIdx - 1 ]);
					passengers [ passengerCount++ ] = copiedPassenger;

					cout << "\n  Profile of " << passengers [ pIdx - 1 ]->getName( )
						<< " copied successfully!\n";
					break;
				}

			case 8: 
				{
					if ( pilotCount == 0 ) {
						cout << "\n  No pilots registered.\n"; break;
					}

					cout << "\n  ========== ALL PILOTS ==========\n";
					for ( int i = 0; i < pilotCount; i++ ) {
						cout << "\n  --- Pilot [" << i + 1 << "] ---\n";
						pilots [ i ]->Person::display( );   // personal info
						pilots [ i ]->Staff::display( );    // staff/employment info
						pilots [ i ]->Pilot::display( );    // pilot-specific info
						cout << "  --------------------------------\n";
					}
					break;
				}

			case 9: 
				{
					if ( crewCount == 0 ) {
						cout << "\n  No cabin crew registered.\n"; break;
					}

					cout << "\n  ========== ALL CABIN CREW ==========\n";
					for ( int i = 0; i < crewCount; i++ ) {
						cout << "\n  --- Crew Member [" << i + 1 << "] ---\n";
						crew [ i ]->Person::display( );        // personal info
						crew [ i ]->Staff::display( );         // staff/employment info
						crew [ i ]->CabinetCrew::display( );   // crew-specific info
						cout << "  ------------------------------------\n";
					}
					break;
				}

			case 10: 
				{
					if ( passengerCount == 0 ) {
						cout << "\n  No passengers registered.\n"; break;
					}

					cout << "\n  ========== ALL PASSENGERS ==========\n";
					for ( int i = 0; i < passengerCount; i++ ) {
						cout << "\n  --- Passenger [" << i + 1 << "] ---\n";
						passengers [ i ]->Person::display( );
						passengers [ i ]->Passenger::display( );
						cout << "  ------------------------------------\n";
					}
					break;
				}

			case 11: 
				{
					if ( flightCount == 0 ) {
						cout << "\n  No flights scheduled.\n"; break;
					}

					cout << "\n  ========== ALL FLIGHTS ==========\n";
					for ( int i = 0; i < flightCount; i++ ) {
						cout << "\n  --- Flight [" << i + 1 << "] ---\n";
						flights [ i ]->display( );
						cout << "  ---------------------------------\n";
					}
					break;
				}

			case 12: 
				{
					if ( ticketCount == 0 ) {
						cout << "\n  No tickets booked.\n"; break;
					}

					cout << "\n  ========== ALL TICKETS ==========\n";
					for ( int i = 0; i < ticketCount; i++ ) {
						cout << "\n  --- Ticket [" << i + 1 << "] ---\n";
						tickets [ i ]->display( );
						cout << "  ---------------------------------\n";
					}
					break;
				}

			case 13:
				{
					cout << "\n  Exiting Al Hashim Airline System...\n";
					break;
				}

			default:
				{
					cout << "\n  Invalid choice. Please enter a number from the menu.\n";
					break;
				}

		}

	}
	while ( choice != 13 );

	clearScreen( );

 
	for ( int i = 0; i < pilotCount; i++ ) 
		delete pilots [ i ];
	for ( int i = 0; i < crewCount; i++ ) 
		delete crew [ i ];
	for ( int i = 0; i < passengerCount; i++ )
		delete passengers [ i ];
	for ( int i = 0; i < seniorCount; i++ ) 
		delete seniorPilots [ i ];
	for ( int i = 0; i < flightCount; i++ ) 
		delete flights [ i ];
	for ( int i = 0; i < ticketCount; i++ ) 
		delete tickets [ i ];

	system("pause");
	return 0;
}
