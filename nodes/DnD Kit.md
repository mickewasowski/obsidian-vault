---
aliases:
context:
  - "[[React Libraries]]"
---

# DnD Kit

A library to help you implement drag and drop actions and reordering of elements.

---

### How to use it
> Necessary packages to install:
> `@dnd-kit/core @dnd-kit/utilities @dnd-kit/sortable`

1. We need to implement a function that is going to be called on drag end
2. Whenever you're adding anything which would involve drag-and-drop you need to surround it with `DndContext`
3. Provide `collisionDetection` algorithm as a prop to the context
4. Implement a wrapper component and wrap all the items you'd want to drag to reorder with `SortableContext`
5. Provide the items to the `SortableContext` and also `stategy`
6. Import `useSortable` hook in the item component - it provides a few important attributes
7. Finally implement the logic for updating the state

Example code:
```jsx
//App.tsx
import {arrayMove} from "@dnd-kit/sortable";

export const App = () => {
    const [tasks, setTasks] = useState([
        { id: 1, title: 'title 1'},
        { id: 2, title: 'title 2'},
        { id: 3, title: 'title 3'},
    ]);

    const getTaskPosition = (id) => tasks.findIndex((x) => x.id === id);

    function handleDragEnd(event: DragEndEvent) {
        const { active, over } = event;
        //active is the element we're currently dragging, over is the element that will be replaced once we let go of the element

        if (active.id === over.id) return; // here we check if the element was let go in the same position (no actual drag)

        setTasks((tasks) =>
            const originalPosition = getTaskPosition(active.id);
            const newPosition = getTaskPosition(over.id);

            return arrayMove(tasks, originalPosition, newPosition);
        );
    }

    return (
        <div>
            <h1>My tasks</h1>
            <DndContext onDragEnd={handleDragEnd} collisionDetection={closestCorners}>
                <Column tasks={tasks}/>
            </DndContext>
        </div>
    );
}

//Column.tsx
import "./Column.css";
import { SortableContext } from "@dnd-kit/sortable";

export const Column = ({ tasks }) => {
    return (<div className="column">
        <SortableContext items={tasks} strategy={verticalListSortingStrategy}>
            {tasks.map((task) => {
                <Task id={task.id} title={task.title} key={task.id} />
            })}
        </SortableContext>
    </div>);
};


//Column.css
.column {
    background-color: #f2f2f3;
    border-radius: 5px;
    padding: 15px;
    width: 80%;
    max-width: 500px;
    display: flex;
    flex-direction: column;
    gap: 15px;
}

//Task.jsx
import "./Task.css";
import {useSortable} from "@dnd-kit/sortable";
import {CSS} from "@dnd-kit/utilities";

export const Task = ({id, title}) => {
    const {attributes, listeners, setNodeRef, transform, transition} = useSortable();

    const style = {
        transition,
        transform: CSS.Transform.toString(transform),
    };

    return (
        <div style={style} ref={setNodeRef} {...attributes} {...listeners} className="task">
            <input type="checkbox" className="checkbox"/>
            {title}
        </div>
    );
};


//Task.css
.task {
    background-color: white;
    border-radius: 5px;
    box-shadow: rgba(0,0,0, 0.16) 0px 1px 4px;
    width: 100%;
    padding: 20px;
    display: flex;
    align-items: center;
    justify-content: flex-start;
    gap: 20px;
    touch-action: none;
}

.checkbox {
    height: 20px;
    width: 20px;
}
```
