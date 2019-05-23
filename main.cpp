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

using TaskInfo     = map<TaskStatus, int>;
using personObject = map<string, TaskInfo>;

class TeamTasks {
public:
  const TaskInfo& GetPersonTasksInfo(const string& person) const{
    auto search = personVocabulary.find(person);
    if(search != personVocabulary.end()){
        return search->second;
      }
    else { //may i do this?
        TaskInfo *t = NULL;
        return *t;
      }
  }

  void AddNewTask(const string& person){
    TaskInfo cleanTask;
    cleanTask.insert(pair<TaskStatus, int>(TaskStatus::NEW,         0));
    cleanTask.insert(pair<TaskStatus, int>(TaskStatus::IN_PROGRESS, 0));
    cleanTask.insert(pair<TaskStatus, int>(TaskStatus::TESTING,     0));
    cleanTask.insert(pair<TaskStatus, int>(TaskStatus::DONE,        0));

    personVocabulary.insert(pair<const string&, TaskInfo>(person, cleanTask)); //cleanTask copy or no?
  }

  tuple<TaskInfo, TaskInfo> PerformPersonTasks(const string& person, int task_count){

    TaskInfo presentTaskInfo = GetPersonTasksInfo(person);

  }

private:
  personObject personVocabulary;
};




int main()
{


  return 0;
}
