# 🌄 FdF — Wireframe Map Renderer

Welcome to **FdF**, a beautiful wireframe map renderer written in C. This project visualizes 3D landscapes from simple map files, transforming raw height data into interactive, artistic wireframe views. Designed with performance and style in mind, FdF brings mathematical maps to life!

---

<p align="center">
  <img src="https://github.com/Denionline/FdF/assets/93453046/your-artwork.png" width="400" alt="FdF Screenshot" />
</p>

---

## 🚀 Features

- **3D Wireframe Rendering:** Generates stunning isometric wireframes from `.fdf` map files.
- **Customizable UI:** Interactive menus and controls for a smooth user experience.
- **Multiple Map Support:** Includes several sample maps to explore (`maps/` directory).
- **Fast Performance:** Optimized drawing routines and FPS tracking.
- **Colorful Visualization:** Supports color-coded maps and artistic overlays.

## 📂 Project Structure

```
FdF/
├── main.c              # Entry point
├── Makefile            # Build automation
├── include/            # Headers and libraries (libft, ft_printf, get_next_line, minilibx)
├── src/                # Source code (renderer, UI, parser, controls, aux)
├── maps/               # Example .fdf map files
└── ...
```

- **src/**: Core modules for rendering, parsing, UI, controls, and math.
- **include/**: Utility libraries (custom printf, GNL, MLX).
- **maps/**: Example heightmaps (try `pyra.fdf`, `plat.fdf`, etc.).

## 🛠️ Build & Run

1. **Clone the repo:**
   ```sh
   git clone https://github.com/Denionline/FdF.git
   cd FdF
   ```

2. **Build:**
   ```sh
   make
   ```

3. **Run with a map:**
   ```sh
   ./fdf maps/pyra.fdf
   ```

## 🗺️ Map Format

Each map file is a grid of integers (optionally with colors), representing height values. Example from [`maps/pyra.fdf`](https://github.com/Denionline/FdF/blob/main/maps/pyra.fdf):

```
0 0 0 ... 0
-1 -1 -1 ... 1
...
```

## 🎮 Controls

- **Explore the UI menu** for interactive options.
- **Keyboard events** and **actions** are handled in the `controls/` modules.

## ✨ Technologies

- **C** — Core language
- **MiniLibX** — Graphics library for rendering
- **libft, ft_printf, get_next_line** — Custom utility libraries

## 📸 Example Maps

- `maps/plat.fdf` — Flat terrain
- `maps/pyra.fdf` — Pyramid
- `maps/10-2.fdf`, `maps/50-4.fdf`, `maps/100-6.fdf`, `maps/10-70.fdf` — Various landscapes

## 💡 Author

Made with ❤️ by [Denionline](https://github.com/Denionline)  
Student at 42 Porto

---

---

> _Results may be incomplete due to response limits. For a full list of files and features, [view the code on GitHub](https://github.com/Denionline/FdF/search)._  
