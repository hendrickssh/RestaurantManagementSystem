#pragma once

#include "stdafx.h"

#include "MenuCategory.h"
#include "Recipe.h"

SharedCode::MenuCategory::MenuCategory() : MenuCategory(NULL) 
{

}

SharedCode::MenuCategory::MenuCategory(string name) : MenuCategory(new string(name)) 
{

}

SharedCode::MenuCategory::MenuCategory(string * name) : name(name), recipes(new RecipeContainer()) 
{

}

SharedCode::MenuCategory::~MenuCategory()
{
   delete this->name;

   for (RecipeContainer::iterator recipeIterator = recipes->begin(); recipeIterator != recipes->end(); recipeIterator++)
   {
      delete *recipeIterator;
      recipeIterator++;
   }

   recipes->clear();
}

void SharedCode::MenuCategory::RemoveRecipe(Recipe * recipeToRemove)
{
	auto it = std::find(recipes->begin(), recipes->end(), recipeToRemove);
	if (it != recipes->end())
		recipes->erase(it);
}

string * SharedCode::MenuCategory::Name()
{
   return name;
}

void SharedCode::MenuCategory::Name(string * name)
{
	delete this->name;

	this->name = name;
}

SharedCode::MenuCategory::RecipeIterator SharedCode::MenuCategory::FirstRecipe()
{
	return recipes->cbegin();
}

SharedCode::MenuCategory::RecipeIterator SharedCode::MenuCategory::LastRecipe()
{
	return recipes->cend();
}

void SharedCode::MenuCategory::AddRecipe(Recipe * recipe)
{
   recipes->push_back(recipe);
}

SharedCode::Recipe * SharedCode::MenuCategory::FindRecipe(Recipe * skeletonRecipe)
{
   for (RecipeIterator recipeIterator = recipes->cbegin(); recipeIterator != recipes->cend(); recipeIterator++)
   {
      if (**recipeIterator == skeletonRecipe)
         return *recipeIterator;
   }
   return nullptr;
}

bool SharedCode::MenuCategory::HasRecipe(Recipe * skeletonRecipe)
{
   return FindRecipe(skeletonRecipe) != nullptr;
}

bool SharedCode::MenuCategory::operator==(MenuCategory * category)
{
   return (name->compare(*category->name)) == 0;
}
