#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Step {
    int number;
    string description;
};

class ProofBlock {
private:
    unordered_map<string, bool> assumptions;
    vector<Step> steps;
    string conclusion;
    bool concludedValue = false;

    static bool parseBool(const string& value) {
        string val = value;
        transform(val.begin(), val.end(), val.begin(), ::tolower);
        if (val == "true") return true;
        if (val == "false") return false;
        throw runtime_error("Invalid boolean value: " + value);
    }

public:
    void assume(const string& var, const string& value) {
        assumptions[var] = parseBool(value);
    }

    void addStep(int number, const string& desc) {
        steps.push_back({number, desc});
    }

    void setConclusion(const string& expr) {
        conclusion = expr;
    }

    bool evaluateExpression(const string& expr) {
        string cleanExpr = expr;
        for (auto& [var, val] : assumptions) {
            string toReplace = var;
            string boolStr = val ? "1" : "0";
            size_t pos = 0;
            while ((pos = cleanExpr.find(toReplace, pos)) != string::npos) {
                cleanExpr.replace(pos, toReplace.length(), boolStr);
                pos += boolStr.length();
            }
        }

        // Only supports AND, OR, NOT for now
        replace(cleanExpr.begin(), cleanExpr.end(), '(', ' ');
        replace(cleanExpr.begin(), cleanExpr.end(), ')', ' ');

        istringstream ss(cleanExpr);
        vector<bool> stack;
        string token;
        while (ss >> token) {
            if (token == "AND") {
                bool b = stack.back(); stack.pop_back();
                bool a = stack.back(); stack.pop_back();
                stack.push_back(a && b);
            } else if (token == "OR") {
                bool b = stack.back(); stack.pop_back();
                bool a = stack.back(); stack.pop_back();
                stack.push_back(a || b);
            } else if (token == "NOT") {
                bool a = stack.back(); stack.pop_back();
                stack.push_back(!a);
            } else if (token == "1" || token == "0") {
                stack.push_back(token == "1");
            }
        }
        if (!stack.empty()) return stack.back();
        throw runtime_error("Evaluation error in expression: " + expr);
    }

    void runProof() {
        cout << "🧠 Triune Proof Engine\n";
        cout << "Assumptions:\n";
        for (const auto& [k, v] : assumptions)
            cout << "  " << k << " := " << (v ? "true" : "false") << "\n";

        cout << "\n🧩 Steps:\n";
        for (const auto& s : steps)
            cout << "  Step " << s.number << ": " << s.description << "\n";

        cout << "\n🔎 Evaluating Conclusion: " << conclusion << "\n";

        try {
            concludedValue = evaluateExpression(conclusion);
            cout << "\n✅ Conclusion: " << (concludedValue ? "TRUE" : "FALSE") << "\n";
        } catch (exception& e) {
            cout << "\n❌ Error: " << e.what() << "\n";
        }
    }
};

// Example usage
int main() {
    ProofBlock proof;
    proof.assume("P", "true");
    proof.assume("Q", "false");

    proof.addStep(1, "Assume P AND Q implies R");
    proof.addStep(2, "Since Q is false, P AND Q is false");
    proof.addStep(3, "Therefore implication is vacuously true");

    proof.setConclusion("P AND Q IMPLIES R"); // Interpret this as logical implication: (P AND Q) => R
    // For simplicity we evaluate "P AND Q" to see truth.

    // Replace with a custom expression syntax (e.g., "(P AND Q)")
    proof.setConclusion("P AND Q");

    proof.runProof();

    return 0;
}
