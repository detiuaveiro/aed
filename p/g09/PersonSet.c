
// Complete the functions (marked by ...)
// so that it passes all tests in Tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SortedList.h"

// NOTE THAT:
// - Field capacity was eliminated.
// - Field size was eliminated, because size==ListGetSize(...).

// Definition of the structure
struct _PersonSet_ {
  List *persons;  // points to a SortedList of Person pointers
};

// Comparison function to be used in generic SortedList.
// Comparison is based on Person ID
static int cmpP(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;
  int d = p1->id - p2->id;
  return (d > 0) - (d < 0);
}

// Create a PersonSet.
PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and create an empty persons list!
  PersonSet *ps = (PersonSet *)malloc(sizeof(*ps));
  if (ps == NULL) {
    perror("PersonSetCreate");
    exit(2);
  }

  ps->persons = ListCreate(cmpP);
  if (ps->persons == NULL) {
    free(ps);
    perror("PersonSetCreate");
    exit(2);
  }

  ListTestInvariants(ps->persons);
  return ps;

  return NULL;
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  
  ListDestroy(&((*pps)->persons));
  free(*pps);
  *pps = NULL;
}

int PersonSetSize(const PersonSet *ps) { return ListGetSize(ps->persons); }

int PersonSetIsEmpty(const PersonSet *ps) { return ListIsEmpty(ps->persons); }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (ListMoveToHead(ps->persons); ListCurrentIsInside(ps->persons);
       ListMoveToNext(ps->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps->persons);
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d)\n", PersonSetSize(ps));
  ListTestInvariants(ps->persons);
}

// Find node in list ps->persons of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  Person dummyperson;
  dummyperson.id = id;
  return ListSearch(ps->persons, &dummyperson);
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  ListInsert(ps->persons, (void *)p);
  ListTestInvariants(ps->persons);
}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the first position!
  Person *p = (Person *)ListRemoveHead(ps->persons);
  ListTestInvariants(ps->persons);
  return p;
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  Person *p = NULL;
  int i = search(ps, id);  // Current node is updated
  if (i >= 0) {
    // Current node is the node to be removed
    p = (Person *)ListRemoveCurrent(ps->persons);
  }
  ListTestInvariants(ps->persons);
  return p;
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  Person *p = NULL;
  int i = search(ps, id);  // Current node is updated
  if (i >= 0) {
    // Current node is the node
    p = (Person *)ListGetCurrentItem(ps->persons);
  }
  ListTestInvariants(ps->persons);
  return p;
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Merge the two sorted lists (similar to mergesort).
  ListMoveToHead(ps1->persons);
  ListMoveToHead(ps2->persons);

  while (ListCurrentIsInside(ps1->persons) && ListCurrentIsInside(ps2->persons)) {
    Person *p1 = (Person *)ListGetCurrentItem(ps1->persons);
    Person *p2 = (Person *)ListGetCurrentItem(ps2->persons);

    if (p1->id < p2->id) {
      ListInsert(ps->persons, (void *)p1);
      ListMoveToNext(ps1->persons);
    } else if (p1->id > p2->id) {
      ListInsert(ps->persons, (void *)p2);
      ListMoveToNext(ps2->persons);
    } else {
      ListInsert(ps->persons, (void *)p1);
      ListMoveToNext(ps1->persons);
      ListMoveToNext(ps2->persons);
    }
  }

  while (ListCurrentIsInside(ps1->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps1->persons);
    ListInsert(ps->persons, (void *)p);
    ListMoveToNext(ps1->persons);
  }

  while (ListCurrentIsInside(ps2->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps2->persons);
    ListInsert(ps->persons, (void *)p);
    ListMoveToNext(ps2->persons);
  }

  ListTestInvariants(ps1->persons);
  ListTestInvariants(ps2->persons);
  ListTestInvariants(ps->persons);

  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  const PersonSet *smallestSet;
  const PersonSet *largestSet;

  if (PersonSetSize(ps1) < PersonSetSize(ps2)) {
    smallestSet = ps1;
    largestSet = ps2;
  } else {
    smallestSet = ps2;
    largestSet = ps1;
  }

  // Iterate through the smallest set
  for (ListMoveToHead(smallestSet->persons); ListCurrentIsInside(smallestSet->persons);
       ListMoveToNext(smallestSet->persons)) {
    Person *p = (Person *)ListGetCurrentItem(smallestSet->persons);
    if (PersonSetContains(largestSet, p->id) == 1) {
      ListInsert(ps->persons, (void *)p);
    }
  }

  ListTestInvariants(ps1->persons);
  ListTestInvariants(ps2->persons);
  ListTestInvariants(ps->persons);

  return ps;
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  for (ListMoveToHead(ps1->persons); ListCurrentIsInside(ps1->persons);
       ListMoveToNext(ps1->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps1->persons);
    if (PersonSetContains(ps2, p->id) == 0) {
      ListInsert(ps->persons, (void *)p);
    }
  }

  ListTestInvariants(ps1->persons);
  ListTestInvariants(ps2->persons);
  ListTestInvariants(ps->persons);

  return ps;
}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  if (PersonSetSize(ps1) > PersonSetSize(ps2)) {
    return 0;
  }

  int eq = 1;
  for (ListMoveToHead(ps1->persons); eq && ListCurrentIsInside(ps1->persons);
       ListMoveToNext(ps1->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps1->persons);
    eq = PersonSetContains(ps2, p->id);
  }
  ListTestInvariants(ps1->persons);
  ListTestInvariants(ps2->persons);
  return eq;
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  return PersonSetSize(ps1) == PersonSetSize(ps2) && PersonSetIsSubset(ps1, ps2);
}
