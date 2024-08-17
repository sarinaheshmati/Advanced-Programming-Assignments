# Vector2D Class

## Overview

This C++ project defines a simple `Vector2D` class for representing and manipulating 2D vectors. The class supports basic vector operations such as addition, subtraction, and dot product.

## Class

### `Vector2D`
Represents a 2D vector with integer components.

- **Private Members**:
  - `int x`: X-coordinate.
  - `int y`: Y-coordinate.

- **Public Methods**:
  - `explicit Vector2D(int x = 0, int y = 0)`: Initializes the vector with optional x and y values.
  - `void setX(int)`: Sets the X-coordinate.
  - `int getX() const`: Returns the X-coordinate.
  - `void setY(int)`: Sets the Y-coordinate.
  - `int getY() const`: Returns the Y-coordinate.
  - `Vector2D operator+(Vector2D)`: Adds two vectors.
  - `Vector2D operator-(Vector2D)`: Subtracts one vector from another.
  - `int operator*(Vector2D)`: Computes the dot product of two vectors.

## Usage

The `Vector2D` class allows for basic operations on 2D vectors, including vector addition, subtraction, and calculating the dot product.
