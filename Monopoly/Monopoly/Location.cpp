#include "Location.h"

Location::Location(wstring name, LocType type, int pos)
{
	Name = name;
	Position = pos;
	Type = type;
}

bool Location::operator<(const Location& loc) const
{
	return Position < loc.Position;
}

bool Location::operator==(const Location& loc) const
{
	return (Name == loc.Name && Position == loc.Position);
}
