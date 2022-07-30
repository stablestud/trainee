#include <iostream>
#include <string>
#include <deque>

enum class CommandType
{
	MoveLeft,
	MoveRight,
	MoveForward,
	MoveBackward
};

std::ostream& operator<<(std::ostream& os, CommandType command)
{
	std::string string;

	switch (command) {
	case CommandType::MoveLeft:
		string = std::string("MoveLeft");
		break;
	case CommandType::MoveRight:
		string = std::string("MoveRight");
		break;
	case CommandType::MoveForward:
		string = std::string("MoveForward");
		break;
	case CommandType::MoveBackward:
		string = std::string("MoveBackward");
		break;
	}
	return os << string;
}

class RoboCommander
{
private:
	std::deque<CommandType> schedule;
	std::deque<CommandType>::iterator itr;
public:
	void AddCommand(CommandType command)
	{
		schedule.push_back(command);
	}

	void UndoCommand(void)
	{
		if (!schedule.empty())
			schedule.pop_back();
	}

	void Execute(void)
	{
		itr = schedule.begin();
		for (;itr < schedule.end(); itr++)
			std::cout << *itr << std::endl;

		std::cout << "Ready\n";
	}
};

int main()
{
	RoboCommander commander;

	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveRight);
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveForward);
	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveForward);
	commander.AddCommand(CommandType::MoveRight);
	commander.AddCommand(CommandType::MoveBackward);
	commander.Execute();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(CommandType::MoveForward);
	commander.Execute();

	return 0;
}
