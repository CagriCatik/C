import clsx from 'clsx';
import Heading from '@theme/Heading';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Core Language Features',
    description: (
      <>
        Understand the basic syntax, keywords, and foundational elements that define C language, including data types, operators, and control structures.
      </>
    ),
  },
  {
    title: 'Memory Management and Pointers',
    description: (
      <>
        Explore concepts of dynamic memory allocation, pointers, and memory handling to efficiently manage resources in C programming.
      </>
    ),
  },
  {
    title: 'Advanced Language Concepts',
    description: (
      <>
        Dive into advanced concepts such as function pointers, macros, inline functions, and optimization strategies.
      </>
    ),
  },
  {
    title: 'Debugging and Error Handling',
    description: (
      <>
        Learn techniques for debugging, diagnosing errors, and implementing error handling mechanisms to create reliable C applications.
      </>
    ),
  },
  {
    title: 'File and I/O Handling',
    description: (
      <>
        Master file operations, input/output handling, and working with streams to manage data and file-based interactions.
      </>
    ),
  },
  {
    title: 'Libraries and Program Organization',
    description: (
      <>
        Understand how to organize programs using modularity, libraries, and header files to create maintainable and scalable projects.
      </>
    ),
  },
  {
    title: 'Data Structures',
    description: (
      <>
        Implement and manipulate essential data structures like arrays, linked lists, stacks, queues, and trees for efficient data management.
      </>
    ),
  },
  {
    title: 'System Programming Concepts',
    description: (
      <>
        Explore low-level system programming concepts, including interacting with hardware, system calls, and operating system interfaces.
      </>
    ),
  },
];

function Feature({ title, description }) {
  return (
    <div className={clsx('col col--3')}>
      <div className="text--center padding-horiz--md">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
