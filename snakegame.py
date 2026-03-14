import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
GRID_SIZE = 20

# Colors
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)

# Screen setup
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Snake Game")
clock = pygame.time.Clock()
font = pygame.font.Font(None, 36)

# Game variables
snake = [(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2)]
food = (random.randint(0, (SCREEN_WIDTH - GRID_SIZE) // GRID_SIZE) * GRID_SIZE,
        random.randint(0, (SCREEN_HEIGHT - GRID_SIZE) // GRID_SIZE) * GRID_SIZE)
direction = (GRID_SIZE, 0)  # Moving right
next_direction = (GRID_SIZE, 0)
score = 0
game_over = False

def draw_grid():
    """Draw grid lines (optional)"""
    for x in range(0, SCREEN_WIDTH, GRID_SIZE):
        pygame.draw.line(screen, (40, 40, 40), (x, 0), (x, SCREEN_HEIGHT))
    for y in range(0, SCREEN_HEIGHT, GRID_SIZE):
        pygame.draw.line(screen, (40, 40, 40), (0, y), (SCREEN_WIDTH, y))

def draw_snake():
    """Draw snake on screen"""
    for i, segment in enumerate(snake):
        if i == 0:  # Head
            pygame.draw.rect(screen, GREEN, (segment[0], segment[1], GRID_SIZE, GRID_SIZE))
            pygame.draw.rect(screen, WHITE, (segment[0], segment[1], GRID_SIZE, GRID_SIZE), 2)
        else:  # Body
            pygame.draw.rect(screen, (0, 200, 0), (segment[0], segment[1], GRID_SIZE, GRID_SIZE))

def draw_food():
    """Draw food on screen"""
    pygame.draw.rect(screen, RED, (food[0], food[1], GRID_SIZE, GRID_SIZE))
    pygame.draw.circle(screen, YELLOW, (food[0] + GRID_SIZE // 2, food[1] + GRID_SIZE // 2), GRID_SIZE // 4)

def draw_score():
    """Draw score text"""
    score_text = font.render(f"Score: {score}", True, WHITE)
    screen.blit(score_text, (10, 10))

def draw_game_over():
    """Draw game over screen"""
    game_over_text = font.render("GAME OVER!", True, RED)
    restart_text = font.render("Press SPACE to Restart or Q to Quit", True, WHITE)
    game_over_rect = game_over_text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 - 50))
    restart_rect = restart_text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 + 50))
    screen.blit(game_over_text, game_over_rect)
    screen.blit(restart_text, restart_rect)

def reset_game():
    """Reset game to initial state"""
    global snake, food, direction, next_direction, score, game_over
    snake = [(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2)]
    food = (random.randint(0, (SCREEN_WIDTH - GRID_SIZE) // GRID_SIZE) * GRID_SIZE,
            random.randint(0, (SCREEN_HEIGHT - GRID_SIZE) // GRID_SIZE) * GRID_SIZE)
    direction = (GRID_SIZE, 0)
    next_direction = (GRID_SIZE, 0)
    score = 0
    game_over = False

def update_game():
    """Update game state"""
    global direction, next_direction, food, score, game_over
    
    if game_over:
        return
    
    direction = next_direction
    
    # Calculate new head position
    new_head = (snake[0][0] + direction[0], snake[0][1] + direction[1])
    
    # Check wall collision
    if (new_head[0] < 0 or new_head[0] >= SCREEN_WIDTH or
        new_head[1] < 0 or new_head[1] >= SCREEN_HEIGHT):
        game_over = True
        return
    
    # Check self collision
    if new_head in snake:
        game_over = True
        return
    
    # Add new head
    snake.insert(0, new_head)
    
    # Check food collision
    if new_head == food:
        score += 10
        food = (random.randint(0, (SCREEN_WIDTH - GRID_SIZE) // GRID_SIZE) * GRID_SIZE,
                random.randint(0, (SCREEN_HEIGHT - GRID_SIZE) // GRID_SIZE) * GRID_SIZE)
    else:
        # Remove tail if no food eaten
        snake.pop()

def handle_input():
    """Handle keyboard input"""
    global next_direction, game_over
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            return False
        
        if event.type == pygame.KEYDOWN:
            # Arrow keys or WASD for movement
            if event.key == pygame.K_UP or event.key == pygame.K_w:
                if direction != (0, GRID_SIZE):  # Can't go opposite direction
                    next_direction = (0, -GRID_SIZE)
            
            elif event.key == pygame.K_DOWN or event.key == pygame.K_s:
                if direction != (0, -GRID_SIZE):
                    next_direction = (0, GRID_SIZE)
            
            elif event.key == pygame.K_LEFT or event.key == pygame.K_a:
                if direction != (GRID_SIZE, 0):
                    next_direction = (-GRID_SIZE, 0)
            
            elif event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                if direction != (-GRID_SIZE, 0):
                    next_direction = (GRID_SIZE, 0)
            
            # Game over controls
            elif event.key == pygame.K_SPACE and game_over:
                reset_game()
            
            elif event.key == pygame.K_q and game_over:
                return False
    
    return True

# Main game loop
def main():
    global score
    
    running = True
    fps = 10
    
    while running:
        running = handle_input()
        
        update_game()
        
        # Draw everything
        screen.fill(BLACK)
        draw_grid()
        draw_snake()
        draw_food()
        draw_score()
        
        if game_over:
            draw_game_over()
        
        pygame.display.flip()
        clock.tick(fps)
    
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()