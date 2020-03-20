#include "cfilterconfigurations.h"

CFilterConfigurations::CFilterConfigurations()
{

}

void CFilterConfigurations::addFilter(const QString &filterLine)
{
    listOfFilters.push_back(filterLine);
}

// TODO: delete filter
// TODO: clear all filters
