#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef vector<double> Vector;

struct PairDistance {
    int index1;
    int index2;
    double angle;
};

double computeMagnitude(const Vector& vec) {
    double sum = 0.0;
    for (double val : vec) {
        sum += val * val;
    }
    return sqrt(sum);
}

double computeCosineAngle(const Vector& a, const Vector& b) {
    double dotProduct = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dotProduct += a[i] * b[i];
    }

    double magnitudeA = computeMagnitude(a);
    double magnitudeB = computeMagnitude(b);
    double cosine = dotProduct / (magnitudeA * magnitudeB);

    cosine = max(-1.0, min(1.0, cosine));

    return acos(cosine);
}

vector<Vector> readVectorsFromFile(const string& filename) {
    ifstream infile(filename);
    vector<Vector> vectors;

    if (!infile) {
        cerr << "Error opening file: " << filename << "\n";
        return vectors;
    }

    string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        Vector vec;
        double value;
        while (iss >> value) {
            vec.push_back(value);
        }
        if (!vec.empty()) {
            vectors.push_back(vec);
        }
    }

    return vectors;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    string inputFileName = argv[1];
    vector<Vector> vectors = readVectorsFromFile(inputFileName);

    if (vectors.size() < 2) {
        cerr << "Need at least two vectors to compute pairwise angles.\n";
        return 1;
    }

    size_t dimension = vectors[0].size();
    for (const Vector& vec : vectors) {
        if (vec.size() != dimension) {
            cerr << "Error: Not all vectors have the same dimension.\n";
            return 1;
        }
    }

    vector<PairDistance> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double angle = computeCosineAngle(vectors[i], vectors[j]);
            distances.push_back({static_cast<int>(i), static_cast<int>(j), angle});
        }
    }

    sort(distances.begin(), distances.end(), [](const PairDistance& a, const PairDistance& b) {
        return a.angle < b.angle;
    });

    cout << fixed << setprecision(4);
    for (const auto& pd : distances) {
        cout << "Vectors (" << pd.index1 << ", " << pd.index2 << ") - Angle: " << pd.angle << " radians\n";
    }

    return 0;
}
