#include <iostream>
#include <vector>
#include  <algorithm>
#include <sstream>
using namespace std;

int main() {
 //vektors ar jautājumiem
  vector<string> questions ={
"1. Kuru galvenes failu nepieciešams iekļut, lai izmantotu vektorus C++?",
"2. Kā deklarēt vektoru ar int elementiem C++?",
"3. Kā pievienot elementu vektora beigās C++?",
"4. Kā iegūt vektora izmēru C++?",
"5. Kā dzēst pēdējo elementu no vektora C++?",
"6. Kā piekļūt vektora elementam pēc indeksa C++?",
"7. Kā pārbaudīt, vai vektors it tukšs C++?",
"8. Kā sakārtot vektora elementus augošā secībā C++?",
"9. Kā dzēst visus elementus no vektora C++?",
"10. Kā nokopēt viena vektora saturu uz citu? "
};
//vektors ar atbildes
  vector<vector<string>> answerChoices = {
  {"1) <vector>", "2) <array>", "3) <list>", "4) <map>"},
  {"1) vector<int> vec;", "2) vector vec<int>;", "3) vector<int> vec{};", "4) vector<int> vec();"},
  {"1) vec.push_back(element);", "2) vec.insert(element);", "3)vec.emplace_back(element); ", "4) vec.add(element);"},
  {"1) vec.size();", "2) vec.count();", "3) vec.lenght();", "4) vec.capacity();"},
  {"1) vec.pop_back();", "2) vec.remove_last();", "3) vec.delete_last();", "4) vec.acces(index);"},
  {"1) vec.get(index);", "2) vec.at(index);", "3) vec[index];", "4) vec.access() == 0;"},
  {"1) vec.empty();", "2) vec.is_empty();", "3) vec.size() == 0;", "4) vec.count() == 0"},
  {"1) sort(vec);", "2) vec.sort();", "3) sort(vec.begin(), vec.end())", "4) vec.sort(vec.begin(), vec.end());"},
  {"1) vec.clear();", "2) vec.delete_all();", "3) vec.erase(vec.begin(), vec.end())", "4) vec.remove_all();"},
  {"1) vec2 == vec1;", "2) vec2.copy(vec1);", "3) copy(vec1.begin(), vec1.end(), vec2.begin())", "4) vec2 = copy(vec1);"}
  };

  //vektors ar pareizās atbildes uz jaut.
  vector<vector<int>> correctAnswers = {
  {0, 1},
  {0, 2},
  {0, 2},
  {0, 3},
  {0, 3},
  {1, 2},
  {0, 2},
  {2, 3},
  {0, 2},
  {0, 2}
};
  int score = 0;
  vector<vector<int>> userAnswers;
 
  cout << "Laipni lūdzam C++ vektoru testā" << endl;
  cout << "Tā kā šis tests tiks uzdots skolotājiem, tad pēc kārtas būs jāatbild uz 10 jautājumiem, katram jautājumam ir 2 pareizās atbildes." << endl;
  cout << "Atbildiet uz sekojošiem jautājumiem" << endl;

 //visu testa jaut. nokārtošana
  for (int i = 0; i<questions.size(); i++){
    cout << questions[i] << endl;
  
    // Izvadīt pašreizējā jautājuma atbilžu variantus
    for (int j=0; j< answerChoices[i].size(); ++j) {
    cout << answerChoices[i][j] << endl;
  }
  string answer; 
    bool validAnswer = false;

    //atbildes saņemšana no lietotāja
    while(!validAnswer) {
      cout << "Ievadiet pareizo atbilžu numurus, atdalot tos ar komatu (piemēram 1,3): ";
   
    getline(cin,answer);
      vector<int> selectedAnswers;
      stringstream ss(answer);
      string token;


      //rindas dalīšana ar atlasīto atbilžu skaitu
      while(getline(ss, token, ',')) {
        int answerIndex = stoi(token) - 1;
        if (answerIndex >=0 && answerIndex < answerChoices[i].size()) {
          selectedAnswers.push_back(answerIndex);
        }else{
          cout << "Kļūda: Nekorekta atbilžu izvēle." << endl;
          selectedAnswers.clear();
          break;
        }
      }
      if (selectedAnswers.empty()) {
        continue;
      }
    sort(selectedAnswers.begin(), selectedAnswers.end());

      //izvēlēto atbilžu pareizības pārbaude
      if (selectedAnswers.size() != correctAnswers[i].size()){
        cout << "Kļuda: Jāizvēlas " << correctAnswers[i].size() << " atbilžu variantu(-i)." << endl;
        continue;
      }
    if (selectedAnswers == correctAnswers[i]){
      score++;
    } else if (selectedAnswers.size() == 1){
    score += 0.5;
    
    }
  userAnswers.push_back(selectedAnswers);
  validAnswer = true;
    }
  }
cout << "Test ir baidzies!" << endl;
  cout << "Jūs iegut " << score << " punktus no " <<
    (questions.size() + 0.5 * count(correctAnswers.begin(),
    correctAnswers.end(), vector<int>{0})) << "." << endl;

  //nepareizu atbilžu izvadīšana
  if (score < (questions.size() + 0.5 *count(correctAnswers.begin(), correctAnswers.end(), vector<int>{0}))) {
    cout << "Nepareizas atbildes:" << endl;
    for (int i = 0; i < questions.size(); i++) {
      if (userAnswers[i] != correctAnswers[i]) {
        cout << "Jautājums " << (i + 1) << ":" << endl;
        cout << questions[i] << endl;
        cout << "Pareizās atbildes: ";

        //Izvadīt pareizās atbildes uz pašreizējo jautājumu

        for (int answerIndex : correctAnswers[i]) {
          cout << answerChoices[i][answerIndex] << " ";
        }
      cout << endl;
      }
    }
  }
  string playAgain;
  cout << "Vai vēlaties spēlēt vēlreiz? (j/n)";
  getline(cin, playAgain);

  if (playAgain == "j" || playAgain == "J") {
    main();
  } else {
    cout << "Paldies par spēli! Uz redzēšanos!" << endl;
  }
}
