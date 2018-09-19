#pragma once

#include "stdafx.h"
#include <iostream>
#include <tinyxml2.h>
#include "RestaurantMenu.h"

using namespace tinyxml2;

SharedCode::RestaurantMenu * SharedCode::RestaurantMenu::ImportMenu(string filePath)
{
	XMLDocument doc;
	doc.LoadFile(filePath.c_str());
    
	if (doc.Error())
		return nullptr;

	XMLElement * rootElement = doc.RootElement();

	XMLElement * menuElement = rootElement->FirstChildElement("Menu");

	XMLElement * categoryElement = menuElement->FirstChildElement("Category");

	RestaurantMenu * menu = new RestaurantMenu();
	while (categoryElement != nullptr)
	{
		string * categoryName = 
			new string(
				categoryElement->Attribute("Name"));

		MenuCategory * category = new MenuCategory(categoryName);

		menu->AddCategory(category);

		XMLElement * recipeElement = categoryElement->FirstChildElement();

		while (recipeElement != nullptr)
		{
			category->AddRecipe(
				new Recipe(
					new string(recipeElement->Attribute("Name")),
					recipeElement->FloatAttribute("Price"),
					new string(recipeElement->Attribute("Description"))));

			recipeElement = recipeElement->NextSiblingElement();
		}

		categoryElement = categoryElement->NextSiblingElement();
	}

	return menu;
}

void SharedCode::RestaurantMenu::ExportMenu(string filePath, SharedCode::RestaurantMenu * menu)
{
	XMLDocument doc;

	doc.LoadFile(filePath.c_str());
	
	if (doc.ErrorID() != XMLError::XML_SUCCESS)
		doc.InsertFirstChild(doc.NewElement("Restaurant"));

	XMLElement * menuElement = doc.NewElement("Menu");

	if (doc.RootElement()->FirstChildElement("Menu"))
		doc.DeleteNode(doc.RootElement()->FirstChildElement("Menu"));

	doc.RootElement()->InsertEndChild(menuElement);

	for (CategoryIterator categoryIterator = menu->FirstCategory(); categoryIterator != menu->LastCategory(); categoryIterator++)
	{
		XMLElement * category = doc.NewElement("Category");
		category->SetAttribute("Name", (*categoryIterator)->Name()->c_str());

		for (MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe(); recipeIterator != (*categoryIterator)->LastRecipe(); recipeIterator++)
		{
			XMLElement * recipe = doc.NewElement("Recipe");
			recipe->SetAttribute("Name", (*recipeIterator)->Name()->c_str());
			
			recipe->SetAttribute("Price", (*recipeIterator)->Price());
			
			recipe->SetAttribute("Description", (*recipeIterator)->Description()->c_str());

			category->InsertEndChild(recipe);
		}

		menuElement->InsertEndChild(category);
	}

	const char * pathcstr = filePath.c_str();

	XMLError megaError = doc.SaveFile(filePath.c_str());
}

SharedCode::RestaurantMenu::RestaurantMenu()
{
   categories = new CategoryContainer();
}


SharedCode::RestaurantMenu::~RestaurantMenu()
{
   for (CategoryContainer::iterator categoryIterator = categories->begin(); categoryIterator != categories->end(); categoryIterator++)
   {
      delete *categoryIterator;
      categoryIterator++;
   }
   categories->clear();
}

void SharedCode::RestaurantMenu::AddCategory(MenuCategory * category)
{
   categories->push_back(category);
}

SharedCode::MenuCategory * SharedCode::RestaurantMenu::FindCategory(string name)
{
   SharedCode::MenuCategory skeletonCategory(new string(name));

   return SharedCode::RestaurantMenu::FindCategory(&skeletonCategory);
}

SharedCode::MenuCategory * SharedCode::RestaurantMenu::FindCategory(MenuCategory * skeletonCategory)
{
   CategoryIterator iterator = categories->begin();

   while (iterator != categories->end())
   {
      if (**iterator == skeletonCategory)
         return *iterator;
      iterator++;
   }
   return nullptr;
}

void SharedCode::RestaurantMenu::RemoveCategory(MenuCategory * categoryToRemove)
{
	auto it = std::find(categories->begin(), categories->end(), categoryToRemove);
	if (it != categories->end())
		categories->erase(it);
}

SharedCode::RestaurantMenu::CategoryIterator SharedCode::RestaurantMenu::FirstCategory()
{
   return categories->cbegin();
}

SharedCode::RestaurantMenu::CategoryIterator SharedCode::RestaurantMenu::LastCategory()
{
	return categories->cend();
}

int SharedCode::RestaurantMenu::CategoryCount()
{
	return (int)categories->size();
}

bool SharedCode::RestaurantMenu::HasCategory(MenuCategory * skeletonCategory)
{
   return FindCategory(skeletonCategory) != nullptr;
}

SharedCode::Recipe * SharedCode::RestaurantMenu::FindRecipe(string recipeName)
{
   Recipe skeletonRecipe(new string(recipeName));
   return FindRecipe(&skeletonRecipe);
}

SharedCode::Recipe * SharedCode::RestaurantMenu::FindRecipe(Recipe * skeletonRecipe)
{
   for (CategoryIterator categoryIterator = categories->begin(); categoryIterator != categories->end(); categoryIterator++)
   {
      if ((*categoryIterator)->HasRecipe(skeletonRecipe))
      {
         return (*categoryIterator)->FindRecipe(skeletonRecipe);
      }
   }
   return nullptr;
}

int SharedCode::RestaurantMenu::numCategories()
{
   return (int)categories->size();
}