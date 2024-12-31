# Virtual Painter

## Overview
The **Virtual Painter** is an interactive project that transforms real-world movements into virtual brushstrokes. Using computer vision techniques, it enables users to paint on a digital canvas by detecting specific colors in a live video feed.

## Features
- **Color Detection**: Utilizes the HSV (Hue, Saturation, Value) color space for precise color masking and tracking.
- **Dynamic Drawing**: Detects and traces the movement of a specified color, filling it like a virtual paintbrush on the screen.
- **Contour Detection**: Leverages contour-detection algorithms to track the shape and movement of the selected color.

## What I Learned
- **Image Preprocessing**: Techniques for improving image quality and isolating features.
- **HSV Color Space**: Applying color masking to detect specific colors efficiently.
- **Contour Detection**: Using contours to trace and follow the movement of objects.

## How It Works
1. The system detects a specific color in the video feed using HSV masking.
2. Contour detection identifies the color's movement and draws its path on the virtual canvas.
3. The selected color acts as a virtual brush, filling in strokes dynamically as it moves.

This project demonstrates the powerful combination of computer vision techniques for creative applications.
