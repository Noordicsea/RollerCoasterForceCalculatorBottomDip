#include <iostream>
#include <string>

using namespace std;

void explainStep(const string& step) {
    if (step == "gravity") {
        cout << "The force due to gravity, also known as weight, is calculated by multiplying the mass by the acceleration due to gravity.\n";
    }
    else if (step == "centripetal") {
        cout << "The centripetal force is the force that keeps an object moving in a circle. It's directed towards the center of the circle and calculated by the formula: mass * (velocity^2) / radius.\n";
    }
    else if (step == "total") {
        cout << "The total force exerted by the seat on the passenger is the sum of the gravitational force and the centripetal force.\n";
    }
}

bool checkUnderstanding() {
    string response;
    cout << "Do you understand this step? (Y/N): ";
    cin >> response;
    return response == "Y" || response == "y";
}

int main() {
    double mass, velocity, radius;
    const double gravity = 9.8; // Acceleration due to gravity in m/s^2

    while (true) {
        cout << "Enter the mass of the passenger (in kg): ";
        cin >> mass;

        cout << "Enter the velocity of the roller-coaster (in m/s): ";
        cin >> velocity;

        cout << "Enter the radius of the circular dip (in m): ";
        cin >> radius;

        // Gravitational force calculation
        cout << "Calculating gravitational force..." << endl;
        double gravitational_force = mass * gravity;
        cout << "Gravitational force (weight) = mass * gravity = " << mass << " * " << gravity << " = " << gravitational_force << " N" << endl;
        if (!checkUnderstanding()) {
            explainStep("gravity");
            continue;
        }

        // Centripetal force calculation
        cout << "Calculating centripetal force..." << endl;
        double centripetal_force = mass * (velocity * velocity) / radius;
        cout << "Centripetal force = mass * (velocity^2) / radius = " << mass << " * (" << velocity << "^2) / " << radius << " = " << centripetal_force << " N" << endl;
        if (!checkUnderstanding()) {
            explainStep("centripetal");
            continue;
        }

        // Total force calculation
        cout << "Calculating total force exerted by the seat on the passenger..." << endl;
        double total_force = gravitational_force + centripetal_force;
        cout << "Total force = gravitational force + centripetal force = " << gravitational_force << " + " << centripetal_force << " = " << total_force << " N" << endl;
        if (!checkUnderstanding()) {
            explainStep("total");
            continue;
        }

        cout << "The total force exerted by the seat on the passenger is: " << total_force << " N" << endl;

        // Ask if the user wants to calculate another force
        cout << "Do you want to calculate another force? (Y/N): ";
        string doAgain;
        cin >> doAgain;
        if (doAgain != "Y" && doAgain != "y") {
            break;
        }
    }

    return 0;
}
