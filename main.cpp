#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

enum class TaskStatus
{
  NEW,
  IN_PROGRESS,
  TESTING,
  DONE
};

struct taskCounter{
  int n;
  int inP;
  int t;
  int d;
};

using TaskInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  const TaskInfo& GetPersonTasksInfo(const string& person) const{
    map<string, taskCounter>::iterator it;
    it = personVocabulary.find(person);
    return ;
  }

  void AddNewTask(const string& person){
    taskCounter newTC{0, 0, 0, 0};
    personVocabulary.insert(pair<const string&, taskCounter&>(person, newTC)); //newTC copy or no?
  }

  tuple<TaskInfo, TaskInfo> PerformPersonTasks(const string& person, int task_count){

  }

private:
  map<string, taskCounter> personVocabulary;
 // map<string, taskCounter>::iterator it;

  struct TTvoc{
    string Person;
    TaskInfo Tsk;
  };
};




int main()
{
  return 0;
}
