interface Person {
    id: number;
    floorSource: number;
    floorDestination: number;
  }

  /** Returns a randomly generated Person object. */
  function createPerson() : Person {
    let src : number = Math.random() * MAX_FLOORS;
    let dest : number = Math.random() * MAX_FLOORS;
    while (dest == src) {
        let dest : number = Math.random() * MAX_FLOORS;
        console.log("hey");
    }
    return {id: Math.random() * 1000000, floorSource: src, floorDestination: dest};
  }

  createPerson();