# miniRT - A Simple Ray Tracer

miniRT is a simple ray tracing engine developed as part of the 42 school curriculum. It is written in C and uses the `minilibx` library for window management and pixel plotting. The program can parse a scene description file (`.rt`) and render it, simulating effects like lighting, shadows, reflections, and refractions to produce computer-generated imagery.

## 📸 Screenshots

Here are a few scenes rendered with miniRT, showcasing different materials and lighting conditions.

![Glass and metal spheres in a mirrored room.](screenshots/Screenshot%20from%202025-06-30%2017-20-12.png)
*Glass and metal spheres in a mirrored room.*
![A glass and mirror sphere](screenshots/Screenshot%20from%202025-06-30%2017-20-38.png)
*A glass and mirror sphere.*
![Primary colors of light](screenshots/Screenshot%20from%202025-06-30%2017-21-17.png)
*Primary colors of light.*
![Spheres in several colors](screenshots/Screenshot%202025-05-18%20at%2019.40.47.png)
*Spheres in several colors.*
![Spheres, a cylinder and a plane](screenshots/Screenshot%202025-05-20%20at%201.19.19.png)
*Spheres, a cylinder and a plane.*

## ✨ Features

- **Phong Lighting Model**: Simulates ambient, diffuse, and specular lighting for realistic shading.
- **Hard Shadows**: Objects cast shadows on each other.
- **Geometric Primitives**: Render scenes with Spheres, Planes, and Cylinders.
- **Material System**:
    - `MAT_DIFFUSE`: Standard matte surface.
    - `MAT_MIRROR`: Perfect reflections.
    - `MAT_METAL`: Metallic surfaces with specular highlights.
    - `MAT_GLASS`: Transparent material with refraction.
- **Camera**: Configurable position, orientation, and vertical Field of View (FOV).
- **Anti-Aliasing**: Uses multi-sampling (4x SPP) for smoother, higher-quality renders.
- **Recursive Ray Tracing**: Supports a reflection/refraction depth of up to 5 bounces.

## 🧑‍💻 Contributors

This project was a collaborative effort by:

- **Ken Ishii**
    - [@kenrio](https://github.com/kenrio)
	- 42 login: keishii
- **Tsubasa Ishihara**
    - [@Anya-Stella](https://github.com/Anya-Stella)
	- 42 login: tishihar

### Development Period

The project was developed from **May 2nd, 2025** to **May 25th, 2025**.

## 🚀 Getting Started

### Prerequisites

- A C compiler (e.g., `gcc` or `clang`).
- `make`.
- On macOS, you will need to install X11 libraries via [Homebrew](https://brew.sh/):
  ```sh
  brew install libx11 libxext libbsd
  ```
- On Linux, you will need `libx11-dev`, `libxext-dev`, `libbsd-dev`, and `libm`.

### Compilation

1.  **Clone the repository (if you haven't already):**
    ```sh
    git clone <your-repo-url>
    cd miniRT
    ```
2.  **Build the project:**
    The Makefile will automatically build `libft`, `minilibx`, and the main `miniRT` executable.
    ```sh
    make
    ```

### Usage

To render a scene, run the executable with the path to a `.rt` scene file as an argument.

```sh
./miniRT scene/test_lights.rt
```

Several example scenes are available in the `scene/` directory.

## 📝 Scene File Format

Scenes are described in `.rt` files. Each element is defined on a new line with a type identifier followed by its parameters.

- **Ambient Light**: `A [intensity] [r,g,b]`
  - `intensity`: Light intensity in range [0.0, 1.0].
  - `r,g,b`: Color values in range [0-255].

- **Camera**: `C [x,y,z] [vec_x,y,z] [fov]`
  - `x,y,z`: Camera position.
  - `vec_x,y,z`: Normalized orientation vector.
  - `fov`: Horizontal field of view in degrees [0-180].

- **Light**: `L [x,y,z] [intensity] [r,g,b]`
  - `x,y,z`: Light source position.
  - `intensity`: Light brightness in range [0.0, 1.0].
  - `r,g,b`: Color values in range [0-255].

- **Sphere**: `sp [x,y,z] [diameter] [r,g,b] [material]`
  - `x,y,z`: Sphere center.
  - `diameter`: Sphere diameter.
  - `r,g,b`: Color values.
  - `material`: (Optional) `MAT_DIFFUSE`, `MAT_MIRROR`, `MAT_METAL`, `MAT_GLASS`.

- **Plane**: `pl [x,y,z] [vec_x,y,z] [r,g,b] [material]`
  - `x,y,z`: A point on the plane.
  - `vec_x,y,z`: Normalized normal vector.
  - `r,g,b`: Color values.
  - `material`: (Optional) See Sphere.

- **Cylinder**: `cy [x,y,z] [vec_x,y,z] [diameter] [height] [r,g,b] [material]`
  - `x,y,z`: Center of the cylinder's base.
  - `vec_x,y,z`: Normalized axis vector.
  - `diameter`: Cylinder diameter.
  - `height`: Cylinder height.
  - `r,g,b`: Color values.
  - `material`: (Optional) See Sphere.

## ⌨️ Controls

- **`ESC` key**: Close the window and terminate the program.
