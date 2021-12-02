# ft_container
In this project, you will implement the various container types of the C++ standard template library. For each container, turn in the appropriately named class files. The namespace will always be ft and your containers will be tested using ft::&lt;container>. You need to respect the structure of the reference container. If it’s missing a part of the orthodox canonical form, do not implement it. As a reminder, we are coding in C++98, so any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected.
## Developer :
 <ul>
    <li><b>Mojahid BELAMAN</b> &nbsp;&nbsp;=> <a href="https://www.linkedin.com/in/mojahid-belaman/" target="_blank">LinkedIn</a></li>
 </ul>

## Subject :
 <ul style="list-style-type:disc;">
    <li>Implement the following containers and turn in the necessary files <container>.hpp</li>
    <li>You must also provide a main.cpp which tests everything for your evaluations. (you
        need to go further than the example!)</li>
    <li>You must produce one binary with only your containers and one with the same
        testing with STL containers.</li>
    <li>Compare outputs and timing (you can be up to 20 times slower).</li>
    <li>member functions, Non-member and overloads are expected.</li>
    <li>respect the naming, take care to details.</li>
    <li>You must use std::allocator.</li>
    <li>You must justify your inner data structure for each container (using a simple array
        for a map is not ok).</li>
    <li>If the container has an iterator system, you must implement it.</li>
    <li>iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented.</li>
    <li>You can use <a href="https://www.cplusplus.com/" target="_blank">https://www.cplusplus.com/</a> and <a href="https://cppreference.com/" target="_blank">https://cppreference.com/ </a>as
        references.</li>
    <li>You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function/-
variable must be justified.</li>
    <li>For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.</li>
    <li>
      You must turn in the following containers and their associated functions:
      <ul style="list-style-type:disc;">
          <li>Vector</li>
          <li>Map</li>
          <li>Stack</li>
      </ul>
    </li>
   <p>Your stack will use your vector class as default underlaying container, it must still be
compatible with others containers like the STL one.
STL containers are forbidden.
You are allowed to use the STD library.</p>
 </ul>

## How To Run Program:
``clang++ -Wall -Wextra -Werror -D NS=ft main_ft.cpp`` => this is my library.<br><br>
``clang++ -Wall -Wextra -Werror -D NS=std main_ft.cpp`` => this is library the system.<br>

# Good Luck :)
